class Solution {
  public:
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        Node* start=head, *end=head;
        int ans=0;
        while(n){
            end=end->next;
            n--;
        }
        while(end){
            end=end->next;
            start=start->next;
        }
        while(start){
            ans+=start->data;
            start=start->next;
        }
        return ans;
        
    }
};
