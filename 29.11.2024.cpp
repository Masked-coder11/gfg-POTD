// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        string ans="";
        int carry=0;
        
        int i=0, j=0;
        while(i<s1.length() && j<s2.length()){
            int val=carry+(s1[i]-'0')+(s2[j]-'0');
            carry=val/2;
            val%=2;
            ans+='0'+val;
            i++;
            j++;
        }
        while(i<s1.length()){
            int val=carry+(s1[i]-'0');
            carry=val/2;
            val%=2;
            ans+='0'+val;
            i++;
        }
        while(j<s2.length()){
            int val=carry+(s2[j]-'0');
            carry=val/2;
            val%=2;
            ans+='0'+val;
            j++;
        }
        while(carry){
            int val=carry;
            carry=val/2;
            val%=2;
            ans+='0'+val;
        }
        
        reverse(ans.begin(), ans.end());
        
        i=0;
        while(i<ans.length() && ans[i]=='0') i++;
        if(i==0) return ans;
        if(i==ans.length()) return "0";
        
        string res="";
        while(i<ans.length()){
            res+=ans[i];
            i++;
        }
        return res;
        
        
    }
};
