class Solution {
  public:
    void bfs(vector<int> graph[], vector<int>&vis, int start){
        queue<int>q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:graph[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return;
    }
    
    bool cycle(vector<int>graph[], int n){
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0]=1;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:graph[node]){
                if(vis[it]){
                    if(parent==it){
                        continue;
                    }
                    else{
                        return true;
                    }
                }
                else{
                    q.push({it, node});
                    vis[it]=1;
                }
            }
        }
        return false;
    }
  
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<int>graph[n];
        for(int i=0;i<m;i++){
            graph[adj[i][0]].push_back(adj[i][1]);
            graph[adj[i][1]].push_back(adj[i][0]);
        }
        
        //check for connected components
        vector<int>vis(n,0);
        int components=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++;
                bfs(graph, vis, i);
            }
        }
        
        if(components > 1){
            return 0;
        }
        
        //check for cycle
        if(cycle(graph,n)){
            return 0;
        }
        return 1;
    }
};
