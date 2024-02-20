class Solution
{
public:
    bool solve(string A, unordered_map<string,int>&mp, int ind){
        if(ind>=A.length()){
            return true;
        }
        
        for(int i=ind;i<A.length();i++){
            string s=A.substr(ind, i-ind+1);
            if(mp.find(s)!=mp.end()){
                if(solve(A, mp, i+1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>mp;
        for(int i=0;i<B.size();i++){
            mp[B[i]]++;
        }
        
        if(solve(A, mp, 0)){
            return true;
        }
        else{
            return false;
        }
    }
};
