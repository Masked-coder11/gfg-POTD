class Solution {
  public:
    bool dfs(int start, vector<int>&vis, vector<int>&pathVis, vector<int>adj[]){
        vis[start]=1;
        pathVis[start]=1;
        
        for(auto it:adj[start]){
            if(vis[it]==0){
                if(dfs(it, vis, pathVis, adj)){
                    return true;
                    
                }
            }
            else if(pathVis[it]==1){
                return true;
            }
        }
        
        pathVis[start]=0;
        
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};
