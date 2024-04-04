class Solution {
  public:
    int LIS(vector<int>&arr){
        int n=arr.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && arr[i]-arr[j]>=i-j){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
        }
        int maxi=0;
        for(auto it:dp){
            maxi=max(maxi, it);
        }
        return maxi;
    }

    int min_operations(vector<int>& nums) {
        // Code here
        int l=LIS(nums);
        int n=nums.size();
        return n-l;
    }
};
