class Solution {
  public:
    bool search(vector<int>&arr, int sum, int lo, int hi){
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==sum) return true;
            else if(arr[mid]<sum) lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
  
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n=arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=arr[i]+arr[j];
                if(search(arr, sum, j+1, n-1)) return true;
            }
        }
        return false;
    }
};
