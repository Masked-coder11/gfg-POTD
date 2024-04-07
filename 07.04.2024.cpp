class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		int dp[m+1][n+1];
		memset(dp, 0, sizeof(dp));
		
		for(int i=1;i<=m;i++){
		    for(int j=i;j<=n;j++){
		        dp[i][j]=max(dp[i-1][j-1]+a[j-1]*b[i-1], dp[i][j-1]);
		    }
		}
		return dp[m][n];
	} 
};
