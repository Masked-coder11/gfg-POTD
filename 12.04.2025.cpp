class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n=image.size(), m=image[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int color=image[sr][sc];
        image[sr][sc]=newColor;
        
        vector<int>vrow={-1,1,0,0};
        vector<int>vcol={0,0,-1,1};
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=row+vrow[i], ncol=col+vcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==color){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=newColor;
                }
            }
            
            
            
        }
        return image;
    }
};
