class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it%k]++;
        }
        for(auto it:mp){
            if(it.first==0 || it.first*2==k){
                if(it.second % 2==1){
                    return false;
                }
            }
            else{
                if(it.second != mp[k-it.first]){
                    return false;
                }
            }
        }
        return true;
    }
};
