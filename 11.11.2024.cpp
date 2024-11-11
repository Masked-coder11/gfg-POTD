class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]){
                ans+=(arr[i-1]+1)-arr[i];
                arr[i]=arr[i-1]+1;
            }
        }
        return ans;
    }
};
