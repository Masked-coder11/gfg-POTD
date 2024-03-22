class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int>ans(n+1);
        ans[0]=0;
        ans[1]=1;
        
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            int x= ans[i-1]+ans[i-2];
            x%=mod;
            ans[i]=x;
        }
        return ans;
    }
};
