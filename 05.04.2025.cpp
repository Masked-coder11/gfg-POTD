class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid,
            int n, int m){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row, col});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0) continue;
                    else{
                        int nrow=row+i, ncol=col+j;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
                        grid[nrow][ncol]=='L'){
                            vis[nrow][ncol]=1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
        return ;
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && vis[i][j]==0){
                    ans++;
                    bfs(i, j, vis, grid, n, m);
                }
            }
        }
        return ans;
        
    }
};
