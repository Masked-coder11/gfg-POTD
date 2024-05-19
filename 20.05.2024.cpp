class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n==0) return 1;
		    if(n==1) return x;
		    
		    long long val= PowMod(x, n/2, M);
		    val=(val*val)%M;
		    
		    if(n%2==1){
		        return (val*x)%M;
		    }
		    
		    return val;
		}
};
