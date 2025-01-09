class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        int s=0, e=0, sum=0;
        while(e<n){
            sum+=arr[e];
            while(sum>target){
                sum-=arr[s];
                s++;
            }
            if(sum==target) return {s+1, e+1};
            e++;
        }
        return {-1};
    }
};
