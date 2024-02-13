//User function Template for C++

class Solution {
public:
    vector<vector<int>>ans;
    int time=0;
    void dfs(int u, vector<int>&tin, vector<int>&lowest, vector<int>&parent, vector<int>adj[]){
        tin[u] = lowest[u] =time++;
        
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(tin[v]==-1){
                parent[v]=u;
                dfs(v, tin, lowest, parent, adj);
                
                if(lowest[v] > tin[u]){
                    ans.push_back({v,u});
                }
                else{
                    lowest[u]=min(lowest[u], lowest[v]);
                }
            }
            else if(tin[v]>-1 && v!=parent[u]){
                lowest[u] = min(lowest[u], lowest[v]);
            }
        }
    }
    
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<int>tin(v,-1);
	    vector<int>lowest(v,-1);
	    
	    vector<int>parent(v,-1);
	    
	    for(int i=0;i<v;i++){
	        if(tin[i]==-1){
	            dfs(i, tin, lowest, parent, adj);
	        }
	    }
	    
	    for(int i=0;i<ans.size();i++){
	        sort(ans[i].begin(), ans[i].end());
	    }
	    sort(ans.begin(), ans.end());
	    
	    return ans;
	    
	    
	    
	    
	}
};
