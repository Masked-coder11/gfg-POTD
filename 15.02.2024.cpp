class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n=paths.size();
	    for(int i=0;i<n;i++){
	        int count=0;
	        for(int j=0;j<n;j++){
	            if(paths[i][j]==1){
	                count++;
	            }
	        }
	        if(count % 2==1){
	            return false;
	        }
	    }
	    
	    return true;
	}

};
