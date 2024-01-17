class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            if(gallery[i]!=-1){
                v.push_back({i-gallery[i], i+gallery[i]});
            }
        }
        int m=v.size();
        sort(v.begin(), v.end());
        int target=0, i=0, ans=0;
        while(target<n && i<m){
            if(v[i].first > target) return -1;
            
            int maxi=v[i].second; i++;
            while(i<m && v[i].first<=target){
                maxi=max(maxi, v[i].second);
                i++;
            }
            target=maxi+1;
            ans++;
        }
        if(target<n-1){
            return -1;
        }
        else{
            return ans;
        }
    }
};
