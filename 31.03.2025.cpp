class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n=s.length();
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        int count=0, curr=-1;
        for(int i=0;i<n;i++){
            curr=max(curr,last[s[i]-'a']);
            if(curr==i){
                count++;
                curr=-1;
            }
        }
        return count;
    }
};
