
class Solution {
  public:
    bool bfs(vector<int>adj[], int start, vector<int>&vis){
        int num=0, edges=0;
        queue<int>q;
        q.push(start);
        vis[start]=1;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            num++;
            edges+=adj[node].size();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        
        return (num*(num-1) == edges);
    }
  
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[v+1];
        for(int i=0;i<e;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>vis(v+1,0);
        int ans=0;
        for(int i=1;i<=v;i++){
            if(bfs(adj, i, vis)){
                ans++;
            }
        }
        return ans;
    }
};
