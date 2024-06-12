
class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int ans=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            for(int x=0; x<s.length();x++){
                if(s[x]=='4'){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
