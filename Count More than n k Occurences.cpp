class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        
        unordered_map<int,int>mp;
        for(int i=0;i<n; i++){
            mp[arr[i]]++;
        }
        
        int ans=0;
        
        for(auto it:mp){
            if(it.second > n/k){
                ans++;
            }
        }
        
        return ans;
    }
};
