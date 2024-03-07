//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int n=s.length();
	    vector<int>freq(26,0);
	    for(int i=0;i<s.length();i++){
	        freq[s[i]-'a']++;
	    }
	    sort(freq.begin(), freq.end());
	    int i=0;
	    while(i<26 && freq[i]==0){
	        i++;
	    }
	    if(i==26) return true;
	    
	    int curr=freq[i];
	    while(i<26 && freq[i]==curr){
	        i++;
	    }
	    if(i==26) return true;
	    
	    if(i==25 && freq[i]-curr==1) return true;
	    
	    return false;
	}
};
