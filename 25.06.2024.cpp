class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>ans(n, vector<int>(m,0));
        k%=m;
        if(k==0) return mat;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=k;j<m;j++,x++){
                ans[i][x]=mat[i][j];
            }
            for(int j=0;j<k;j++,x++){
                ans[i][x]=mat[i][j];
            }
        }
        return ans;
    }
};
