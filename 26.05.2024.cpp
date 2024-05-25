class Solution {

  public:
    int lcs(string x, string y){
        int n=x.length(), m=y.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(x[i-1]==y[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int length=lcs(x,y);
        return costX*(x.length()-length)+costY*(y.length()-length);
        
        
    }
};
