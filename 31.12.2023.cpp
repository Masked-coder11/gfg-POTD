
class Solution {
    
    public:
    int isPossible(int N , int coins[]) 
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=coins[i];
        }
        
        if(sum%20==0 || sum%24==0 || sum==2024){
            return 1;
        }
        
        vector<vector<int>>dp(N+1, vector<int>(sum+1,0));
        for(int i=0;i<=N;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=N;i++){
            for(int x=0;x<=sum;x++){
                dp[i][x]=dp[i-1][x];
                if(x>=coins[i-1]){
                    dp[i][x]= dp[i][x] || dp[i-1][x-coins[i-1]];
                }
                
                if(x>=1 && dp[i][x] && (x%20==0 || x%24==0 || x==2024)){
                    return 1;
                }
            }
            
        }
        
        return 0;
    }
    
};
