//User function template for C++
class Solution{
public:	
    void solve(vector<string>&ans, string curr, int ones, int zeroes, int n){
        if(ones<zeroes) return;
        
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        
        solve(ans, curr+'1', ones+1, zeroes, n);
        solve(ans, curr+'0', ones, zeroes+1, n);
        
        return;
    }

	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    string curr="";
	    
	    solve(ans, curr, 0, 0, n);
	    
	    return ans;
	}
};
