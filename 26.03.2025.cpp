class Solution {
  public:
    int wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int n=s.length();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(auto it: dictionary){
                int start= i- it.size();
                if(start>=0 && dp[start] && s.substr(start, it.size()) == it){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
        
    }
};
