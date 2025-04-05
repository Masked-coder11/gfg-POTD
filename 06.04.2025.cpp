class Solution {
  public:
    void dfs(int start, vector<int>&vis, vector<int>&ans, vector<int>adj[]){
        vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                dfs(it, vis, ans, adj);
            }
        }
        ans.push_back(start);
        return;
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>ans;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, ans, adj);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
