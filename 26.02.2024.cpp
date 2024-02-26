class Solution{
	public:
	    void solve(string s, int ind, string curr, vector<string>&ans){
	        if(ind==s.length()){
	            if(curr.length()>0){
	                ans.push_back(curr);
	            }
	            return;
	        }
	        
	        //take
	        curr.push_back(s[ind]);
	        solve(s, ind+1, curr, ans);
	        
	        //not take
	        curr.pop_back();
	        solve(s, ind+1, curr, ans);
	        
	        return ;
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string curr="";
		    vector<string>ans;
		    int ind=0;
		    solve(s, ind, curr, ans);
		    
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
