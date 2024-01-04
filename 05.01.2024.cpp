class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod=1e9+7;
	    if(N==1) return 4;
	    long long int B=1, S=1, Bn1, Sn1;
	    
	    for(int i=2;i<=N;i++){
	        Bn1 = B;
	        Sn1 = S;
	        
	        //updating our values
	        B = Sn1;
	        S = Bn1 + Sn1;
	        
	        B %=mod;
	        S %=mod;
	       
	    }
	    
	    long long int result = B+S;
	    result %= mod;
	    
	    result = result * result;
	    result %= mod;
	    
	    return result;
	}
};
