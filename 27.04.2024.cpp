
/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* first, Node* second){
        if(!first) return second;
        if(!second) return first;
        
        if(first->data < second->data){
            first->next= merge(first->next, second);
            first->next->prev=first;
            first->prev=NULL;
            
            return first;
        }
        else{
            second->next= merge(first, second->next);
            second->next->prev=second;
            second->prev=NULL;
            
            return second; 
        }
    }
  
    Node* getMid(Node* head){
        Node* fast=head, *slow=head;
        
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        Node* temp=slow->next;
        slow->next=NULL;
        return temp;
    }
  
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(!head || !head->next) return head;
        
        Node* mid= getMid(head);
        
        head=sortDoubly(head);
        mid=sortDoubly(mid);
        
        return merge(head, mid);
    }
};
