class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:arr){
            if(mp[it]==0){
                mp[it]++;
                ans.push_back(it);
            }
        }
        return ans;
    }
};
