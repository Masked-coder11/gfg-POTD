//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            if(it.second!=0){
                pq.push(it.second);
            }
        }
        for(int i=0;i<k;i++){
            int a=pq.top(); pq.pop();
            a--;
            if(a>0){
                pq.push(a);
            }
        }
        int ans=0;
        while(!pq.empty()){
            ans=ans+ pq.top()*pq.top();
            pq.pop();
        }
        return ans;
    }
};
