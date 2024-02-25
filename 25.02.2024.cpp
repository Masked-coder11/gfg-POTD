class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long>v(n+1, 0);
    	v[0]=1;
    	for(int i=3;i<=n;i++){
    	    v[i]+=v[i-3];
    	}
    	for(int i=5;i<=n;i++){
    	    v[i]+=v[i-5];
    	}
    	for(int i=10;i<=n;i++){
    	    v[i]+=v[i-10];
    	}
    	
    	return v[n];
    	
    }
};
