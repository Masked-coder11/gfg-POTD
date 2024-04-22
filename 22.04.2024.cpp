// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int ans=-1, mini=INT_MAX;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    curr++;
                }
            }
            if(curr<mini){
                mini=curr;
                ans=i+1;
            }
        }
        return ans;
    }
};
