class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    vector<int>vis(256,0);
	    string ans="";
	    for(int i=0;i<str.length();i++){
	        if(vis[str[i]]==1){
	            continue;
	        }
	        else{
	            vis[str[i]]=1;
	            ans=ans+str[i];
	        }
	    }
	    return ans;
	}
};
