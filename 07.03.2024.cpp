class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int res_length=0;
        int i, index=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(j-i > dp[i-1][j-1] && s[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>res_length){
                        res_length=dp[i][j];
                        index=max(i,index);
                    }
                }
                else{
                    dp[i][j]=0;
                }
                
            }
        }
        string res="";
        if(res_length>0){
            for(i= index-res_length+1;i<=index;i++){
                res+=s[i-1];
            }
        }
        if(res==""){
            res="-1";
        }
        return res;
    }
};
