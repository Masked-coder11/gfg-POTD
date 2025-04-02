class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size(), m=mat[0].size(), ans=0, count=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<int, pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                    count++;
                }
                else if(mat[i][j]) count++;
            }
        }
        
        vector<int>radd={-1,1,0,0};
        vector<int>cadd={0,0,-1,1};
        while(!q.empty()){
            int t=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            
            ans=max(ans, t);
            count--;
            for(int i=0;i<4;i++){
                int nrow=row+radd[i], ncol=col+cadd[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({t+1,{nrow,ncol}});
                }
            }
            
            
        }
        if(count==0) return ans;
        else return -1;
        
    }
};
