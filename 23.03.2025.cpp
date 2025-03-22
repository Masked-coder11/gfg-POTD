class Solution {
  public:
    int helper(int ind, int n, string &s, vector<int>&dp){
        if(ind==n) return 1;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int ans=0;
        ans+=helper(ind+1, n, s, dp);
        
        if(ind<n-1){
            int num=(s[ind]-'0')*10 + (s[ind+1]-'0');
            if(num<=26){
                ans+=helper(ind+2, n, s, dp);
            }
        }
        return dp[ind] = ans;
    }
  
    int countWays(string &digits) {
        // Code here
        int n=digits.length();
        
        vector<int>dp(n, -1);
        
        return helper(0, n, digits, dp);
        
    }
};
