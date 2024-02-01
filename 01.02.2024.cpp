//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        int n=s.length();
        if(n<26){
            return false;
        }
        
        vector<int>vis(26,0);
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                vis[s[i]-'a']++;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                vis[s[i]-'A']++;
            }
            
        }
        for(int i=0;i<26;i++){
            if(!vis[i]) return false;
        }
        return true;
    }

};
