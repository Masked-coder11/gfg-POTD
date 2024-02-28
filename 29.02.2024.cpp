//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long long ans=0;
	    for(int i=0;i<32;i++){
	        int count=0;
	        for(int j=0;j<n;j++){
	            if(arr[j] & (1<<i)){
	                count++;
	            }
	        }
	        ans+=2LL*(long long)count*(long long)(n-count);
	    }
	    return ans;
	}
};
