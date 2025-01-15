lass Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int ans=0, sum=0;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            
            if(mp.find(sum-k)!=mp.end()){
                ans=max(ans, i-mp[sum-k]);
            }
            else if(sum==k){
                ans=i+1;
            }
        }
        return ans;
    }
};
