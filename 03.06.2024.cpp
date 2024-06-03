class Solution {
  public:
    long long MOD=1e9+7;
    long long power(long long a, long long b){
        long long ans=1;
        while(b>0){
            if(b&1){
                ans*=a;
                ans%=MOD;
            }
            a*=a;
            a%=MOD;
            b >>=1;
        }
        return ans;

    }
  
    int numberOfConsecutiveOnes(int n) {
        // code here
        vector<int>a(n);
        vector<int>b(n);
        
        a[0]=1; b[0]=1;
        for(int i=1;i<n;i++){
            a[i]=(a[i-1]+b[i-1])%MOD;
            b[i]=a[i-1];
        }
        
        return (power(2,n)+MOD - (a[n-1]+b[n-1])%MOD)%MOD;
    }
};
