class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int maxi=0;
        for(auto it:arr) maxi=max(maxi, it);
        
        vector<int>count(maxi+1,0);
        
        for(auto it:arr) count[it]++;
        
        int ans=0;
        for(int i=0;i<=maxi;i++){
            if(count[i]){
                if(k==0){
                    ans+=count[i]*(count[i]-1)/2;
                }
                else if(i+k<=maxi){
                    ans+=count[i]*count[i+k];
                }
            }
        }
        return ans;
    }
};
