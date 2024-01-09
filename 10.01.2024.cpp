//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>mp;
	    int sum=0, ans=0;
	    int i=0;
	    while(i<n){
	        sum+=arr[i];
	        int rem = ((sum%k)+k)%k;
	        if(rem == 0){
	            ans = i+1;
	        }
	        else{
	            if(mp.find(rem)!=mp.end()){
	                ans =max(ans, i-mp[rem]);
	            }
	            else{
	                mp[rem]=i;
	            }
	        }
	        i++;
	    }
	    return ans;
	}
};
