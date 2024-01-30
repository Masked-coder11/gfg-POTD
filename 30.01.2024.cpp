class Solution
{   
    int dp[21][21][21];
    public:
        int solve(string A, string B, string C, int i,int j, int k){
            if(i<0 || j<0 || k<0){
                return 0;
            }
            if(dp[i][j][k]!=-1) return dp[i][j][k];
            if(A[i]==B[j] && B[j]==C[k]){
                return dp[i][j][k]=1+solve(A,B,C,i-1,j-1,k-1);
            }
            else{
                return dp[i][j][k]=max(solve(A,B,C,i-1,j,k),max(solve(A,B,C,i,j-1,k),solve(A,B,C,i,j,k-1)));
            }
        }

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            for(int i=0;i<=n1;i++){
                for(int j=0;j<=n2;j++){
                    for(int k=0;k<=n3;k++){
                        dp[i][j][k]=-1;
                    }
                }
            }
            return solve(A,B,C, n1-1, n2-1, n3-1);
            
        }
};
