class Solution{
    public:
    
    int f(int n, int total, vector<int> &cost, int ind, vector<vector<int>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][total]!=-1) return dp[ind][total];
        
        int take=0;
        if(cost[ind] <= total){
            take = 1+f(n, total - cost[ind] + floor(0.9*cost[ind]), cost, ind+1, dp);
        }
        int not_take=f(n,total, cost, ind+1, dp);
        
        return dp[ind][total]=max(take, not_take);
        
    }
    
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<vector<int>>dp(n+1, vector<int>(total+1,-1));
        int ans = f(n, total, cost, 0, dp);
        return ans;
    }
};
