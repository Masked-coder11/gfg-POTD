class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        for(auto it:s){
            if(freq[it-'a']==1) return it;
        }
        return '$';
    }
};
