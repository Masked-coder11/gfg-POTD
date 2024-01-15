// User function Template for C++

class Solution{
public:
    int solve(int i, int n, int m, vector<vector<int>>&dp){
        if(n==1){
            return 1;
        }
        if(i>=m){
            return 0;
        }
        if(dp[i][n]!=-1) return dp[i][n];
        
        int ans=0;
        for(int x=2*i;x<=m;x++){
            ans+=solve(x, n-1, m, dp);
        }
        return dp[i][n] = ans;
    }
    
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=solve(i, n, m, dp);
        }
        return ans;
    }
};
