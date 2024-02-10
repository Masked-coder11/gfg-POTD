class Solution {
public:

    int dp[101][101][101];
    
    long long solve(int n, int k, vector<vector<int>>&arr, int row, int col){
        if(k<0) return 0;
        if(row==n-1 && col==n-1){
            if(k==arr[row][col]) return 1;
            else return 0;
        }
        
        if(dp[row][col][k]!=-1) return dp[row][col][k];
        
        long long int right=0, down=0;
        if(col+1<n){
            right=solve(n, k-arr[row][col], arr, row, col+1);
        }
        if(row+1<n){
            down=solve(n, k-arr[row][col], arr, row+1, col);
        }
        
        return dp[row][col][k]=right+down;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int l=0;l<=k;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
        
        return solve(n, k, arr, 0, 0);
    }
};
