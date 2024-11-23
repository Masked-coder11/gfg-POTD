class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int sum=0, maxi=arr[0];
        for(auto it:arr){
            sum+=it;
            maxi=max(maxi, sum);
            sum=max(0, sum);
        }
        return maxi;
    }
};
