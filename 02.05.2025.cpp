class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int lo=0, hi=arr.size()-1, ans=INT_MIN;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            ans=max(ans, arr[mid]);
            if(mid==0 || arr[mid-1]<arr[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};
