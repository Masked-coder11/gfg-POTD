class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        vector<pair<int, int>> helper;
        
        for(int i=0;i<n;i++){
            helper.push_back({price[i], i+1});
        }
        
        sort(helper.begin(), helper.end());
        
        int i=0;
        int ans=0;
        
        while(i<n && k>0){
            int maxi= k/helper[i].first;
            int allowed = helper[i].second;
            
            int buying = min(maxi, allowed);
            
            ans+= buying;
            
            k-= buying* helper[i].first;
            
            i++;
            
        }
        
        return ans;
        
    }
};
