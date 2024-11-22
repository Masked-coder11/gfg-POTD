class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n=arr.size();
        
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<=n-2;i++){
            int l=max(arr[n-1]-k, arr[i]+k);
            int s=min(arr[0]+k, arr[i+1]-k);
            
            ans=min(ans, abs(l-s));
        }
        
        return ans;
    }
};
