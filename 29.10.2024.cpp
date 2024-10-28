class Solution {
  public:
    Node* partition(Node* head, Node* tail){
        Node* pivot=head, *prev=head, *temp=head;
        while(temp!=tail->next){
            if(pivot->data > temp->data){
                swap(prev->next->data, temp->data);
                prev=prev->next;
            }
            temp=temp->next;
        }
        
        swap(pivot->data, prev->data);
        
        return prev;
    }
  
    void helper(Node* head, Node* tail){
        if(!head || head==tail){
            return;
        }
        
        Node* pivot=partition(head, tail);
        
        helper(head, pivot);
        helper(pivot->next, tail);
        
        return;
    }
  
    struct Node* quickSort(struct Node* head) {
        // code here
        if(!head || !head->next) return head;
        
        Node* tail=head;
        
        while(tail->next){
            tail=tail->next;
        }
        
        helper(head, tail);
        
        return head;
        
    }
};
