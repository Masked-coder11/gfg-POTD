// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int>ans(n,0);
        set<int>s;
        for(int i=1;i<n;i++){
            int val=ans[i-1]-i;
            if(val>0 && s.find(val)==s.end()){
                s.insert(val);
                ans[i]=val;
            }
            else{
                s.insert(ans[i-1]+i);
                ans[i]=ans[i-1]+i;
            }
        }
        
        return ans;
    }
};
