class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        // we will  be making  by rows and by cols matrices
        int by_rows[n][n];
        int by_cols[n][n];
        for(int i=0;i<n;i++){
            int row=0;
            for(int j=0;j<n;j++){
                if(a[i][j]=='X'){
                    row++;
                }
                else{
                    row=0;
                }
                by_rows[i][j]=row;
            }
            
        }
        for(int i=0;i<n;i++){
            int col=0;
            for(int j=0;j<n;j++){
                if(a[j][i]=='X'){
                    col++;
                }
                else{
                    col=0;
                }
                by_cols[j][i]=col;
            }
        }
        
        int res=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int side=min(by_rows[i][j], by_cols[i][j]);
                while(side>res){
                    if(by_rows[i-side+1][j]>=side && by_cols[i][j-side+1]>=side){
                        res=side;
                    }
                    else{
                        side--;
                    }
                }
            }
        }
        return res;
    }
};
