class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int n=S.length();
        int start=0, end=0;
        int zero=0, one=0, two=0;
        
        int ans = INT_MAX;
        while(end<n){
            while( (end < n) && (!zero || !one || !two)){
                if(S[end]=='0') zero++;
                else if(S[end]=='1') one++;
                else two++;
                
                end++;
            }
            if(zero && one && two){
                ans= min(ans, end-start);
            }
            
            while(start<end && zero && one && two){
                ans=min(ans, end-start);
                if(S[start]=='0') zero--;
                else if(S[start]=='1') one--;
                else two--;
                
                start++;
            }
        }
        
        if(ans==INT_MAX) ans=-1;
        
        return ans;
        
    }
};
