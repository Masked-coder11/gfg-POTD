//User function Template for C++

class Solution{
public:
    int mod=1e9+7;

    long long f(int term, int start, int n){
        if(term > n){
            return 0;
        }
        
        long long int ans=1;
        for(int i=0;i<term;i++){
            ans=ans*start;
            ans=ans%mod;
            start++;
        }
        
        ans=ans+f(term+1, start, n);
        ans=ans%mod;
        
        return ans;
    }

    long long sequence(int n){
        // code here
        long long ans= f(1, 1, n);
        
        return ans;
    }
};
