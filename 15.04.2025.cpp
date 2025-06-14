class Solution {
  public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>ans(n,1e8);
        ans[S]=0;
        
        for(int i=0;i<n-1;i++){
            for(auto it:edges){
                if(ans[it[0]]==1e8) continue;
                else{
                    ans[it[1]]=min(ans[it[1]], ans[it[0]]+it[2]);
                }
            }
        }
        
        for(auto it:edges){
            if(ans[it[0]]==1e8) continue;
            else{
                if(ans[it[1]]>ans[it[0]]+it[2]){
                    return {-1};
                }
            }
        }
        
        return ans;
        
    }
};
