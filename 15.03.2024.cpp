class Solution
{
    public:
    
    Node* merge(Node *head1, Node* head2){
        if(!head1) return head2;
        if(!head2) return head1;
        
        Node* temp=head1;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head2;
        
        return head1;
    }
    
    void reverse(Node *&head){
        Node* prev=NULL, *curr=head, *next;
        
        while(curr){
            next=curr->next;
            curr->next= prev;
            prev = curr;
            curr=next;
        }
        head=prev;
    }
    
    void splitList(Node*head, Node **Ahead, Node**Dhead){
        *Ahead=new Node(0);
        *Dhead=new Node(0);
        
        Node*ascn= *Ahead;
        Node*dscn= *Dhead;
        Node* curr=head;
        while(curr){
            ascn->next=curr;
            ascn=ascn->next;
            curr=curr->next;
            
            if(curr){
                dscn->next=curr;
                dscn=dscn->next;
                curr=curr->next;
            }
        }
        
        ascn->next=NULL;
        dscn->next=NULL;
        
        *Ahead=(*Ahead)->next;
        *Dhead=(*Dhead)->next;
        
        return;
    }
    
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
         Node*Ahead, *Dhead;
         splitList(*head, &Ahead, &Dhead);
         
         reverse(Dhead);
         
         *head=merge(Ahead, Dhead);
         
         return;
    }
};
