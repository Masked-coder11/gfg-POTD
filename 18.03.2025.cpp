class Solution {
  public:
    
    bool helper(int ind, vector<int>&arr, int target, vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==arr.size()) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        
        bool take=false, not_take=false;
        if(arr[ind]<=target) take=helper(ind+1, arr, target-arr[ind], dp);
        not_take = helper(ind+1, arr, target, dp);
        
        return dp[ind][target] = take || not_take;
    }
  
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(auto it:arr) sum+=it;
        if(sum%2!=0) return false;
        
        vector<vector<int>>dp(n, vector<int>(sum+1,-1));
        
        return helper(0, arr, sum/2, dp);
    }
};
