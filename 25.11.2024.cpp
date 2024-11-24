class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        int curr=1, ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(curr==0) curr=1;
            
            curr=curr*arr[i];
            ans=max(ans, curr);
        }
        
        curr=1;
        for(int i=n-1;i>=0;i--){
            if(curr==0) curr=1;
            curr=curr*arr[i];
            ans=max(ans, curr);
        }
        return ans;
    }
};
