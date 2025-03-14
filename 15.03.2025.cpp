class Solution {
  public:
    int helper(int ind, int sum, vector<int>&coins, vector<vector<int>>&dp){
        if(sum==0) return 0;
        if(ind==coins.size()) return 1e9;
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        int take=1e9, not_take=1e9;
        if(coins[ind]<=sum) take=1+helper(ind, sum-coins[ind], coins, dp);
        not_take=helper(ind+1, sum, coins, dp);
        
        return dp[ind][sum] = min(take, not_take);
    }
  
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
        
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        int ans=helper(0, sum, coins, dp);
        
        if(ans==1e9) return -1;
        return ans;
        
        
    }
};
