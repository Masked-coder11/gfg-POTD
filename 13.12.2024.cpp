class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int ans=arr[0], lo=0, hi=arr.size()-1;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            ans=min(ans, arr[mid]);
            
            if(arr[lo]<=arr[mid]){
                ans=min(ans, arr[lo]);
                lo=mid+1;
            }
            else if(arr[mid]<=arr[hi]){
                hi=mid-1;
            }
        }
        return ans;
    }
};
