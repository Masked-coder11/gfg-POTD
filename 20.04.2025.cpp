class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            int idx=abs(arr[i]);
            if(arr[idx]<0) return idx;
            else arr[idx]=-arr[idx];
        }
        return -1;
    }
};
