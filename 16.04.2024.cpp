
class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code herei
        vector<int>post_max(n,0);
        vector<int>post_min(n,0);
        post_max[n-1]=arr[n-1];
        post_min[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            post_max[i]=max(arr[i], post_max[i+1]);
            post_min[i]=min(arr[i], post_min[i+1]);
        }
        
        int ans=post_max[k]-post_min[k];
        
        int maxi=arr[0], mini=arr[0];
        
        for(int i=1;i<n-k;i++){
            ans=min(ans, max(post_max[i+k],maxi) - min(post_min[i+k],mini));
            
            maxi=max(arr[i], maxi);
            mini=min(arr[i], mini);
        }
        
        ans=min(ans, maxi-mini);
        
        return ans;
    }
};
