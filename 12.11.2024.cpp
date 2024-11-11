class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(), arr.end());
        for(int i=1;i<arr.size();i++){
            if(arr[i][0] < arr[i-1][1]){
                return false;
            }
        }
        return true;
    }
};
