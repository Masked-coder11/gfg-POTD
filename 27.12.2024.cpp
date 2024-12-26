class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int req=target-arr[i];
            ans+=mp[req];
            mp[arr[i]]++;
            
        }
        return ans;
    }
};
