// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        int n=S.length();
        if(K==0) return S;
        else if(K==n) return "0";
        
        stack<char>st1;
        st1.push(S[0]);
        for(int i=1;i<n;i++){
            while(!st1.empty() && st1.top()>S[i] && K!=0){
                K--;
                st1.pop();
            }
            st1.push(S[i]);
        }
        
        while(K!=0){
            K--;
            st1.pop();
        }
        
        stack<char>st2;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        
        while(st2.size()!=1 && st2.top()=='0'){
            st2.pop();
        }
        
        string res="";
        while(!st2.empty()){
            res+=st2.top();
            st2.pop();
        }
        
        return res;
    }
};
