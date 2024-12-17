class Solution {
  public:
    bool check(vector<int>&arr, int k, int mid){
        int number=1, pages=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid) return false;
            if(pages+arr[i]>mid){
                pages=arr[i];
                number++;
            }
            else{
                pages+=arr[i];
            }
        }
        if(number<=k) return true;
        return false;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k) return -1;
        int lo=0, hi=0;
        for(auto it:arr) hi+=it;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(arr, k, mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};
