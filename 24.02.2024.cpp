class Solution
{
    public:
        int solve(int n, vector<int>&dp){
            if(n==0 || n==1) return n;
            if(dp[n]!=-1) return dp[n];
            
            return dp[n]=max(n, solve(n/2,dp)+solve(n/3,dp) + solve(n/4,dp));
        }
        
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n+1, -1);
            return solve(n,dp);
        }
};
