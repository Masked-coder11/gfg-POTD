class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k!=0){
	        return 0;
	    }
	    
	    else{
	        unordered_map<string,int>mp;
	        
	        for(int i=0;i<n;i+=k){
	            mp[s.substr(i,k)]++;
	        }
	        
	        if(mp.size()==1){
	            return 1;
	        }
	        
	        if(mp.size()==2){
	            for(auto it:mp){
	                if(it.second==1){
	                    return 1;
	                }
	                
	            }
	        }
	        
	        return 0;
	    }
	    
	    
	}
};
