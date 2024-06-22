// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        long long ans=-1;
        long long curr=0;
        int i=0, n=s.length();
        while(i<n){
            curr=0;
            bool flag=true;
            while(i<n && s[i]!=' '){
                if(flag && s[i]>='0' && s[i]<='8'){
                    curr=curr*10+(s[i]-'0');
                }
                else{
                    flag=false;
                }
                i++;
            }
            i++;
            if(flag){
                ans=max(ans, curr);
            }
        }
        return ans;
    }
};
