class Solution {
  public:
  
  int helper(int ind, int mode, int k, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(ind==prices.size()) return 0;
        if(k==0) return 0;
        if(dp[ind][k][mode]!=-1) return dp[ind][k][mode];
        
        if(mode==0){
            // buy
            return dp[ind][k][mode] = max(helper(ind+1, !mode, k,prices, dp)-prices[ind],
                        helper(ind+1, mode, k, prices, dp));
        }
        else{
            return dp[ind][k][mode] = max(helper(ind+1, !mode, k-1, prices, dp)+prices[ind],
            helper(ind+1, mode, k, prices, dp));
        }
    }
  
    int maxProfitK(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(k+1, vector<int>(2,-1)));
        
        return helper(0, 0, k, prices, dp);
        
    }
    
  
    int maxProfit(vector<int> &prices) {
        // code here
        return maxProfitK(prices, 2);
    }
};
