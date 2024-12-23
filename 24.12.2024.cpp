class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(), m=mat[0].size();
        int lo=0, hi=n*m-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            
            int row=mid/m, col=mid%m;
            
            if(mat[row][col]==x) return true;
            else if(mat[row][col]>x) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};
