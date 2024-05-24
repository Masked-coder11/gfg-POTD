class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long ans=0, curr=0;
        int i=0;
        while(i<n){
            if(arr[i]<=k){
                curr+=arr[i];
            }
            else{
                curr=0;
            }
            
            ans=max(ans, curr);
            i++;
        }
        return ans;
    }
};
