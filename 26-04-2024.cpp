class Solution {
  public:
    vector<int>ans;
    
    vector<int> solve(int n, int m,int i,int j,int p, int dir,vector<vector<int>>& mat){
        if(i>=n || j>=m ||i<0 ||j<0){
            return ans;
        }
        
        if(mat[i][j]==0){
            ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            int a=0,b=0;
            if(dir==0||dir==2){
                b=b+p;
            }else if(dir==1 || dir==3){
                a=a+p;
            }
            
            solve(n,m,i+a,j+b,p,dir,mat);
        }else{
            if(dir==0){
               ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i+1,j,1,1,mat);
            
            }else if(dir==1){
                 ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i,j-1,-1,2,mat);
            }else if(dir==2){
                 ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i-1,j,-1,3,mat);
            }else if(dir==3){
                 ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i,j+1,1,0,mat);
            }
            
            
        }
        return ans;
        
    }
    
    
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        solve(n,m,0,0,1,0,matrix);
        
        return ans;
        
    }
};
