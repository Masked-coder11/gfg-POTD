class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n=str.length(), start=0, end=0, distinct=0, count=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[str[i]]++;
            if(mp[str[i]]==1) distinct++;
        }
        
        unordered_map<char,int>curr;
        int ans=n;
        while(end<n){
            curr[str[end]]++;
            if(curr[str[end]]==1) count++;
            end++;
            
            while(curr[str[start]]>1){
                curr[str[start]]--;
                start++;
            }
            
            if(count==distinct){
                ans=min(ans, end-start);
            }
        }
        return ans;
    }
};
