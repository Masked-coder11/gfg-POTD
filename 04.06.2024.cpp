class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        reverse(s.begin(), s.end());
        int carry=1;
        for(int i=0;i<s.length() && carry==1;i++){
            if(s[i]=='0'){
                s[i]='1';
                carry=0;
            }
            else{
                s[i]='0';
                carry=1;
            }
        }
        if(carry){
            s=s+'1';
        }
        reverse(s.begin(), s.end());
        int idx=0;
        while(s[idx]=='0'){
            idx++;
        }
        int n=s.length();
        return s.substr(idx,n-idx);
    }
};
