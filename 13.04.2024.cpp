class Solution {
  public:
    long long reversedBits(long long x) {
        // code h'ere
        string s="";
        for(int i=0;i<=31;i++){
            if(x & (1<<i)){
                s='1'+s;
            }
            else{
                s='0'+s;
            }
        }
        
        long long ans=0;
        for(int i=0;i<=31;i++){
            if(s[i]=='1'){
                ans+=pow(2,i);
            }
        }
        return ans;
    }
};
