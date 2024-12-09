class Solution {
  public:
    int minRemoval(vector<vector<int>> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int ans=0, end=arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]<end){
                ans++;
                end=min(end, arr[i][1]);
            }
            else{
                end=arr[i][1];
            }
        }
        return ans;
    }
};
