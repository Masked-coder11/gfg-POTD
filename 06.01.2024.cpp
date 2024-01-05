
class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    //create the pre-requisite table
	    vector<int>v(b+1,-1);
	    v[0]=0; v[1]=1;
	    for(int i=2;i<=b;i++){
	        if(v[i]==-1){
	            //remained unvisited
	            for(int x=i;x<=b;x+=i){
	                v[x]=i;
	            }
	        }
	    }
	    
	    int ans=0;
	    for(int i=a;i<=b;i++){
	        int x=i;
	        while(x>1){
	            ans++;
	            x = x/v[x];
	            
	        }
	    }
	    return ans;
	}
};
