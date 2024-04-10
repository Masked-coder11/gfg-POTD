class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        string b="";
        for(int i=0;i<=31;i++){
            if(n & (1<<i)){
                b='1'+b;
            }
            else{
                b='0'+b;
            }
        }
        
        int idx=0;
        for(int i=0;i<=31;i++){
            if(b[i]=='1'){
                idx=i;
                break;
            }
        }
        b=b.substr(idx, 32-idx);
        
        string g="";
        g+=b[0];
        int a=b[0]-'0';
        for(int i=1;i<b.length();i++){
            int x=b[i]-'0';
            if(a^x){
                g=g+'1';
                a=1;
            }
            else{
                g=g+'0';
                a=0;
            }
        }
        
        int ans=0;
        for(int i=0;i<g.length();i++){
            ans=ans*2 + (g[i]-'0');
        }
        
        return ans;
        
    }
};
