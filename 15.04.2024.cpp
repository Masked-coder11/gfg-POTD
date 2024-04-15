class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, max(a[i], b[i]));
        }
        
        vector<int>arr(maxi+1,0);
        for(int i=0;i<n;i++){
            arr[b[i]]++;
        }
        
        for(int i=1;i<=maxi;i++){
            arr[i]+=arr[i-1];
        }
        
        vector<int>ans;
        for(auto it:query){
            ans.push_back(arr[a[it]]);
        }
        
        return ans;
    }
};
