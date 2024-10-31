class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        long long sum=0;
        for(int i=0;i<n/2;i++){
            sum+=2*(arr[n-i-1]);
            sum-=2*arr[i];
        }
        return sum;
    }
};
