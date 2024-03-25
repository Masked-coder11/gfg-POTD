// User function template for C++
class Solution {
  public:
  string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res="";
        int i=0;
        int carry=0;
        while(i<min(num1.length(), num2.length())){
            int x=carry;
            x+=num1[i]-'0';
            x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(i<num1.length()){
            int x=carry;
            x+=num1[i]-'0';
            // x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(i<num2.length()){
            int x=carry;
            // x+=num1[i]-'0';
            x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(carry){
            int x=carry;
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
        }
        reverse(res.begin(), res.end());

        return res;

    }
    bool isAdditiveSequence(string num) {
        // Your code here
        int n=num.length();
        if(n<3) return false;
        for(int i=1;i<=n/2;i++){
            for(int j=1;max(i,j)<=n-i-j;j++){
                string first=num.substr(0,i);
                string second=num.substr(i,j);
                
                if(first.length()>1 && first[i]=='0'){
                    break;
                }
                if(second.length()>1 && second[i]=='0'){
                    break;
                }
                
                int start=i+j;
                string sum;
                while(start<n){
                    sum=addStrings(first, second);
                    if(start+sum.length()>n || sum!=num.substr(start, sum.length())){
                        break;
                    }
                    first=second;
                    second=sum;
                    start+=sum.length();
                }
                if(start==n){
                    return true;
                }
            }
        }
        return false;
    }
};
