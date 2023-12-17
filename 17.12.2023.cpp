class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int* arr, int n, int ind, vector<int>&dp){
	    if(ind>=n){
	        return 0;
	    }
	    
	    if(dp[ind]!=-1){
	        return dp[ind];
	    }
	    
	    int take=arr[ind]+solve(arr, n, ind+2, dp);
	    int not_take= solve(arr,n, ind+1, dp);
	    
	    return dp[ind]=max(take, not_take);
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    int ind=0;
	    vector<int>dp(n,-1);
	    int ans=solve(arr,n, ind, dp);
	    
	    return ans;
	}
};
