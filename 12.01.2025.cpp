class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>v(n, 0);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi, arr[i]);
            v[i]=maxi;
        }
        
        maxi=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi, arr[i]);
            
            ans+=max(0, min(maxi, v[i])-arr[i]);
        }
        
        return ans;
    }
};
