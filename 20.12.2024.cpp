class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int>ans;
        int top=0, left=0, bottom=mat.size()-1, right=mat[0].size()-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            if(top>bottom) break;
            
            for(int i=top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(left>right) break;
            
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            if(top>bottom) break;
            
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
        return ans;
    }
};
