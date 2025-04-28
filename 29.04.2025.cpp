class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // code here
        Node* temp=head;
        int zero=0, one=0, two=0;
        while(temp){
            if(temp->data==0) zero++;
            else if(temp->data==1) one++;
            else two++;
            
            temp=temp->next;
        }
        
        temp=head;
        while(zero){
            temp->data=0;
            zero--;
            temp=temp->next;
        }
        while(one){
            temp->data=1;
            one--;
            temp=temp->next;
        }
        while(two){
            temp->data=2;
            two--;
            temp=temp->next;
        }
        return head;
        
    }
};
