class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        vector<int>freq(26,0);
        for(auto it:s1){
            freq[it-'a']++;
        }
        for(auto it:s2){
            freq[it-'a']--;
        }
        for(auto it:freq){
            if(it!=0) return false;
        }
        return true;
    }
};
