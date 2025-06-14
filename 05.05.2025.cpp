class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==target) return mid;
            else if(mid-1>=0 && arr[mid-1]==target) return mid-1;
            else if(mid+1<n && arr[mid+1]==target) return mid+1;
            
            else if(arr[mid]<target){
                lo=mid+2;
            }
            else{
                hi=mid-1;
            }
        }
        return -1;
        
    }
};
