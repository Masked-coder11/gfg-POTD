class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int ans=0;
	    int r1=0, c1=0; // top left
	    int r2=n-1, c2=n-1; // bottom right
	    
	    while(r1<n && r2>=0){
	        int sum=mat1[r1][c1] + mat2[r2][c2];
	        if(sum==x){
	            ans++;
	            c1++;
	            c2--;
	        }
	        else if(sum<x){
	            c1++;
	        }
	        else{
	            c2--;
	        }
	        
	        if(c1==n){
	            r1++;
	            c1=0;
	        }
	        if(c2<0){
	            r2--;
	            c2=n-1;
	        }
	    }
	    
	    return ans;
	    
	}
};
