class Solution {
  public:
    void helper(int node, vector<int>&ans, vector<int>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                helper(it, ans, vis, adj);
            }
        }
        return;
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>ans;
        helper(0, ans, vis, adj);
        return ans;
    }
};
