class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int lo=0, hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==key) return mid;
            if(arr[lo]<=arr[mid]){
                if(key>=arr[lo] && key<=arr[mid]){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                if(arr[mid]<=key && arr[hi]>=key){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};
