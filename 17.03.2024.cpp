class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        set<int>st;
        Node* temp=head1;
        while(temp){
            st.insert(temp->data);
            temp=temp->next;
        }
        
        int ans=0;
        temp=head2;
        while(temp){
            int val=temp->data;
            if(st.find(x-val)!=st.end()){
                ans++;
            }
            temp=temp->next;
        }
        return ans;
    }
};
