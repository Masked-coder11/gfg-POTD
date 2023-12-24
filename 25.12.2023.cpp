class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        
        if(n==1) return matrix[0][0];
        
        else if(n==2) return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        
        int ans=0;
        int sign=1;
        for(int column=0;column<n;column++){
            int element = matrix[0][column]*sign;
            sign = -sign;
            
            //construct the smaller matrix
            vector<vector<int>>smat;
            for(int i=1;i<n;i++){
                vector<int>row;
                for(int j=0;j<n;j++){
                    if(j!=column){
                        row.push_back(matrix[i][j]);
                    }
                }
                smat.push_back(row);
            }
            
            int deter = determinantOfMatrix(smat, n-1);
            
            ans+= deter*element;
        }
        
        return ans;
    }
};
