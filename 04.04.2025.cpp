class Solution {
  public:
    bool helper(int start, vector<int>adj[], vector<int>&vis){
        vis[start]=1;
        queue<pair<int,int>>q;
        q.push({-1, start});
        while(!q.empty()){
            int parent=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({node, it});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
