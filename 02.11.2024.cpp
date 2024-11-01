class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]!=0) return true;
            
            if(i-k>=0) mp[arr[i-k]]--;
            
            mp[arr[i]]++;
        }
        return false;
    }
};
