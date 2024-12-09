class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &arr,
                                       vector<int> &x) {
        // code here
        vector<vector<int>>ans;
        int n=arr.size();
        int i=0;
        while(i<n && arr[i][1]<x[0]){
            ans.push_back(arr[i]);
            i++;
        }
        while(i<n && arr[i][0]<=x[1]){
            x[0]=min(x[0], arr[i][0]);
            x[1]=max(x[1], arr[i][1]);
            i++;
        }
        ans.push_back(x);
        while(i<n){
            ans.push_back(arr[i]);
            i++;
        }
        return ans;
    }
};
