//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int sign=1;
        int i=0;
        if(s[0]=='-'){
            sign=-1;
            i++;
        }
        int ans=0;
        for(;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                ans=ans*10+(s[i]-'0');
            }
            else{
                return -1;
            }
        }
        return ans*sign;
    }
};
