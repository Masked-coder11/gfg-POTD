class Solution {
  public:
    int helper(int ind, vector<int>&arr, vector<int>&dp){
        if(ind>=arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int steal=arr[ind]+helper(ind+2,arr, dp);
        int notSteal = helper(ind+1, arr, dp);
        
        return dp[ind] = max(steal, notSteal);
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n, -1);
        
        return helper(0, arr, dp);
    }
};
