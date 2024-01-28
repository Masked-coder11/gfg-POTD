class Solution {
  public:
    vector<vector<vector<long long int>>>dp;
  
    long long findNthNumber(int n, int k) {
        // code here
        long long low=0, hi=1e18;
        dp.resize(2, vector<vector<long long int>>(65, vector<long long int>(65)));
        
        while(low<=hi){
            long long mid = low +(hi-low)/2;
            long long count = find(mid,k);
            if(count>=n){
                hi=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    long long find(long long n, int k){
        string s = bitset<64>(n).to_string();
        reset();
        return dpf(s, s.length(), 1, k);
    }
    
    long long dpf(string &s, int n, int tight, int k){
        if(k<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[tight][k][n]!=-1) return dp[tight][k][n];
        
        int ub;
        if(tight==1){
            ub=s[s.length()-n]-'0';
        }
        else{
            ub=1;
        }
        long long ans=0;
        for(int dig=0;dig<=ub;dig++){
            if(dig==ub){
                ans+=dpf(s,n-1,tight,k-dig);
            }
            else{
                ans+=dpf(s,n-1,0,k-dig);
            }
        }
        
        return dp[tight][k][n]=ans;
        
    }
    
    void reset(){
        for(int i=0;i<65;i++){
            for(int j=0;j<65;j++){
                dp[0][i][j]=-1;
                dp[1][i][j]=-1;
            }
        }
    }
};
