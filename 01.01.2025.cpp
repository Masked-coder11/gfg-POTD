class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        
        for(int i=0;i<arr.size();i++){
            string s=arr[i];
            sort(s.begin(), s.end());
            
            mp[s].push_back(arr[i]);
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
