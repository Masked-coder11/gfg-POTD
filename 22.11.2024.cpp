class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxi=0, ans=0;
        for(int i=prices.size()-1;i>=0;i--){
            maxi=max(maxi, prices[i]);
            ans=max(ans, maxi-prices[i]);
        }
        return ans;
    }
};
