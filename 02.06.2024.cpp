class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &arr) {
        // code here
        vector<int>ans;
        int x=0;
        
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i][0]==0){
                ans.push_back(x^arr[i][1]);
            }
            else{
                x^=arr[i][1];
            }
        }
        ans.push_back(0^x);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
