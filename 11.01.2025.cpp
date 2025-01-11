class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int start=0, end=0, ans=0;
        unordered_map<char, int>mp;
        
        while(end<s.length()){
            mp[s[end]]++;
            while(mp[s[end]]==2){
                mp[s[start]]--;
                start++;
            }
            
            ans=max(ans, end-start+1);
            end++;
        }
        return ans;
        
    }
};
