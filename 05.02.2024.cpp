class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       Node * n= new Node(data);
       
       if(!head){
           n->next=n;
           return n;
       }
       
       //case 2
       if(head->data >= data){
            Node* temp=head;
            while(temp->next !=head){
                temp=temp->next;
            }
            temp->next=n;
            n->next=head;
            return n;
       }
       
       //case 3
       Node* temp=head;
       while(temp->next!=head && temp->next->data < data){
           temp=temp->next;
       }
       n->next=temp->next;
       temp->next=n;
       
       return head;
    
    }
};
