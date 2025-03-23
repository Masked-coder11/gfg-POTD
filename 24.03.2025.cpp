class Solution {
  public:
    int helper(int start, int end,  vector<int>&arr, vector<vector<int>>&dp){
        if(end-start==1) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        
        int ans=INT_MAX;
        for(int k=start+1;k<end;k++){
            int left=helper(start, k, arr, dp);
            int right=helper(k, end, arr, dp);
            ans=min(ans, left+right+arr[start]*arr[k]*arr[end]);
        }
        return dp[start][end] = ans;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return helper(0, n-1, arr, dp);
        
    }
};
