class Solution {
  public:
    int isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<int>adj[V];
        for(auto it:edges){
            if((it[0]==c && it[1]==d) || (it[0]==d && it[1]==c)){
                continue;
            }
            else{
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        }
        
        vector<int>vis(V,0);
        queue<int>q;
        q.push(c);
        vis[c]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        if(vis[d]==0){
            return true;
        }
        else{
            return false;
        }
    }
};
