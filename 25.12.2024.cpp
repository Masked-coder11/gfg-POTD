class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        int flag=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    if(i==0){
                        flag=0;
                    }
                    else{
                        mat[i][0]=0;
                        mat[0][j]=0;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
        
        if(mat[0][0]==0){
            for(int i=0;i<n;i++) mat[i][0]=0;
        }
        
        if(flag==0){
            for(int j=0;j<m;j++) mat[0][j]=0;
        }
        
        return ;
    }
};
