class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto it:arr) mp[it]++;
        
        int ans=0;
        for(int i=0;i<n;i++){
            int x=arr[i];
            if(mp.find(x-1)==mp.end()){
                while(mp.find(x)!=mp.end()){
                    x++;
                }
                ans=max(ans, x-arr[i]);
            }
        }
        return ans;
    }
};
