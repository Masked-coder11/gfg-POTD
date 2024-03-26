//User function Template for C++

class Solution
{
public:
    bool check(int i, int j, vector<vector<int>>&mat){
        if(i-1>=0 && mat[i-1][j]==0) return false;
        if(i+1<mat.size() && mat[i+1][j]==0) return false;
        if(j-1>=0 && mat[i][j-1]==0) return false;
        if(j+1<mat[0].size() && mat[i][j+1]==0) return false;
        
        return true;
    }
    
    int solve(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&vis, vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || vis[i][j]==1 || mat[i][j]==0) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(!check(i,j,mat)) return INT_MAX;
        
        if(j==0) return mat[i][0];
        
        vis[i][j]=true;
        
        int left=solve(i, j-1, mat, vis, dp);
    
        int up=solve(i-1, j, mat, vis, dp);
        
        int down=solve(i+1, j, mat, vis, dp);
        
        if(left!=INT_MAX) left+=mat[i][j];
        if(up!=INT_MAX) up+=mat[i][j];
        if(down!=INT_MAX) down+=mat[i][j];
        
        vis[i][j]=0;
        
        return dp[i][j]=min(left, min(up, down));
    }

    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int n=mat.size();
       int m=mat[0].size();
       vector<vector<int>>vis(n, vector<int>(m,0));
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
           mini=min(mini, solve(i, m-1, mat, vis,dp));
       }
       
       if(mini==INT_MAX) return -1;
       else return mini;
       
    }
};
