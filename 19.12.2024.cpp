class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        int hi=n-1, lo=0, res=k+n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>mid+k){
                res=mid+k;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return res;
    }
};
