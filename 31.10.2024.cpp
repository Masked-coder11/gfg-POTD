class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node* a= new Node();
        a->data=x;
        a->prev=NULL;
        a->next=NULL;
        
        if(head==NULL) return a;
        
        // front
        if(head->data >= x){
            a->next=head;
            head->prev=a;
            
            return a;
        }
        
        Node* prev=NULL, *temp=head;
        while(temp){
            if(temp->data < x){
                prev=temp;
                temp=temp->next;
            }
            else{
                temp->prev=a;
                a->next=temp;
                
                a->prev=prev;
                prev->next=a;
                
                return head;
            }
        }
        
        // rear
        prev->next=a;
        a->prev=prev;
        
        return head;
    
    }
};
