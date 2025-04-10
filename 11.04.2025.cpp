class Solution {
  public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[2], it[1]});
            adj[it[1]].push_back({it[2], it[0]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        vector<int>dist(n, 1e9);
        dist[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                if(dist[it.second] > wt + it.first){
                    dist[it.second] = wt+it.first;
                    pq.push({dist[it.second], it.second});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
        
    }
};
