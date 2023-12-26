class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        int n=matrix.size();
        
        vector<int>ans;
        
        for(int x=0;x<n;x++){
            int i=0;
            int j=x;
            while(i<n && j>=0){
                ans.push_back(matrix[i][j]);
                i++;
                j--;
            }
        }
        
        for(int x=1;x<n;x++){
            int i=x;
            int j=n-1;
            
            while(i<n && j>=0){
                ans.push_back(matrix[i][j]);
                i++;
                j--;
            }
        }
        
        return ans;
    }
};
