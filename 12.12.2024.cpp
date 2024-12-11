class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first=-1, last=-1;
        int lo=0, hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==target){
                first=mid;
                hi=mid-1;
            }
            else if(arr[mid]<target){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        lo=0;
        hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==target){
                last=mid;
                lo=mid+1;
            }
            else if(arr[mid]<target){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if(last==-1){
            return 0;
        }
        return last-first+1;
    }
};
