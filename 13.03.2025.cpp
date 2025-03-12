class Solution {
  public:
    int helper(int ind, int W, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        if(ind==val.size()) return 0;
        if(W==0) return 0;
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        
        int take=0, not_take=0;
        if(wt[ind]<=W) take=val[ind]+helper(ind+1, W-wt[ind], val, wt, dp);
        
        not_take =helper(ind+1, W, val, wt, dp);
        
        return dp[ind][W] = max(take, not_take);
    }
  
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        
        return helper(0, W, val, wt, dp);
        
        
    }
};
