class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        vector<int>ans;
        stack<int>st;
        int val=1;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                ans.push_back(val);
                st.push(val);
                val++;
            }
            else if(str[i]==')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};
