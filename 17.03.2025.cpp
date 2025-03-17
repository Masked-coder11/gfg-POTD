class Solution {
  public:
    bool helper(int ind, vector<int>&arr, int sum, vector<vector<int>>&dp){
        if(sum==0) return true;
        if(ind==arr.size()) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        bool take=false, not_take=false;
        if(arr[ind]<=sum) take=helper(ind+1, arr, sum-arr[ind], dp);
        not_take=helper(ind+1, arr, sum, dp);
        
        return dp[ind][sum]= take || not_take;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1,-1));
        
        return helper(0, arr, sum, dp);
        
    }
};
