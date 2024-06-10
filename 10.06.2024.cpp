class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        for(int i=0;i<n;i++){
            if(nuts[i]=='!'){
                nuts[i]='0';
            }
            else if(nuts[i]=='#'){
                nuts[i]='1';
            }
            else if(nuts[i]=='$'){
                nuts[i]='2';
            }
            else if(nuts[i]=='%'){
                nuts[i]='3';
            }
            else if(nuts[i]=='&'){
                nuts[i]='4';
            }
            else if(nuts[i]=='*'){
                nuts[i]='5';
            }
            else if(nuts[i]=='?'){
                nuts[i]='6';
            }
            else if(nuts[i]=='@'){
                nuts[i]='7';
            }
            else if(nuts[i]=='^'){
                nuts[i]='8';
            }
            
            if(bolts[i]=='!'){
                bolts[i]='0';
            }
            else if(bolts[i]=='#'){
                bolts[i]='1';
            }
            else if(bolts[i]=='$'){
                bolts[i]='2';
            }
            else if(bolts[i]=='%'){
                bolts[i]='3';
            }
            else if(bolts[i]=='&'){
                bolts[i]='4';
            }
            else if(bolts[i]=='*'){
                bolts[i]='5';
            }
            else if(bolts[i]=='?'){
                bolts[i]='6';
            }
            else if(bolts[i]=='@'){
                bolts[i]='7';
            }
            else if(bolts[i]=='^'){
                bolts[i]='8';
            }
            
        }
        
        sort(nuts, nuts+n);
        sort(bolts, bolts+n);
        
        for(int i=0;i<n;i++){
            if(nuts[i]=='0'){
                nuts[i]='!';
            }
            else if(nuts[i]=='1'){
                nuts[i]='#';
            }
            else if(nuts[i]=='2'){
                nuts[i]='$';
            }
            else if(nuts[i]=='3'){
                nuts[i]='%';
            }
            else if(nuts[i]=='4'){
                nuts[i]='&';
            }
            else if(nuts[i]=='5'){
                nuts[i]='*';
            }
            else if(nuts[i]=='6'){
                nuts[i]='?';
            }
            else if(nuts[i]=='7'){
                nuts[i]='@';
            }
            else if(nuts[i]=='8'){
                nuts[i]='^';
            }
            
            if(bolts[i]=='0'){
                bolts[i]='!';
            }
            else if(bolts[i]=='1'){
                bolts[i]='#';
            }
            else if(bolts[i]=='2'){
                bolts[i]='$';
            }
            else if(bolts[i]=='3'){
                bolts[i]='%';
            }
            else if(bolts[i]=='4'){
                bolts[i]='&';
            }
            else if(bolts[i]=='5'){
                bolts[i]='*';
            }
            else if(bolts[i]=='6'){
                bolts[i]='?';
            }
            else if(bolts[i]=='7'){
                bolts[i]='@';
            }
            else if(bolts[i]=='8'){
                bolts[i]='^';
            }
            
        }
        
        
    }
};
