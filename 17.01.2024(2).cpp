//User function Template for C++

class Solution {
  public:
    void solve(vector<int>&arr, int n, int ind, set<vector<int>>&s){
        if(ind>=n){
            return ;
        }
        for(int i=ind;i<n;i++){
            swap(arr[i], arr[ind]);
            s.insert(arr);
            solve(arr, n, ind+1, s);
            
            swap(arr[i], arr[ind]);
        }
        return;
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        //using next perm
        
        // sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        
        solve(arr, n, 0, s);
        
        for(auto it:s){
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
