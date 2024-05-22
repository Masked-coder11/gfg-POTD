class Solution{
public:
    int lcs(string& s, string& r, int i, int j, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==r[j]){
            return dp[i][j]=1+lcs(s,r, i-1, j-1, dp);
        }
        
        return dp[i][j]=max(lcs(s, r, i-1,j,dp), lcs(s,r,i,j-1,dp));
    }

    int kPalindrome(string str, int n, int k)
    {
        // code here
        string r=str;
        reverse(r.begin(), r.end());
        
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        
        int x=lcs(str, r, n-1, n-1, dp);
        
        int rem=n-x;
        return rem<=k;
    }
};
