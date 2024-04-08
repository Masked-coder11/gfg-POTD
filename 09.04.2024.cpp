class Solution{

	public:
		int minPoints(int m, int n, vector<vector<int>> arr) 
	{ 
	    
	    int ans[m][n];
	  
	    ans[m-1][n-1] = arr[m-1][n-1] > 0? 1: 
	                   abs(arr[m-1][n-1]) + 1; 
	  
	    for (int i = m-2; i >= 0; i--) 
	         ans[i][n-1] = max(ans[i+1][n-1] - arr[i][n-1], 1); 
	    for (int j = n-2; j >= 0; j--) 
	         ans[m-1][j] = max(ans[m-1][j+1] - arr[m-1][j], 1); 
	   
	    for (int i=m-2; i>=0; i--) 
	    { 
	        for (int j=n-2; j>=0; j--) 
	        {  
	            ans[i][j] = max(min(ans[i+1][j], ans[i][j+1])-arr[i][j], 1); 
	        } 
	     } 
	  
	     return ans[0][0]; 
	} 
};
