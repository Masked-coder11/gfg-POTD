// User function Template for C++
class Solution{
public:
    pair<string,int> solve(int p[], int n, int i, int j, vector<vector<pair<string,int>>>&v){
        if(i==j){
            string s="";
            s+='A'+i-1;
            return {s,0};
            
        }
        
        if(v[i][j].second!=-1) return v[i][j];
        int mini=INT_MAX;
        string sr="";
        for(int k=i;k<=j-1;k++){
            pair<string,int>left=solve(p, n, i, k,v);
            pair<string,int>right=solve(p,n,k+1,j,v);
            
            int steps =left.second + right.second + p[i-1]*p[k]*p[j];
            
            
            if(steps<mini){
                sr='('+left.first+right.first+')';
                mini=steps;
                
            }
        }
        return v[i][j]={sr, mini};
    }
    
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<pair<string,int>>>v(n, vector<pair<string,int>>(n,{"",-1}));
        
        pair<string,int> operations = solve(p, n , 1, n-1, v);
        
        //forming the name
        
        return operations.first;
        
    }
};
