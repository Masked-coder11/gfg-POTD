class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int ans=0, l=0, r=arr.size()-1;
        
        while(l<r){
            ans=max(ans, min(arr[l],arr[r])*(r-l));
            
            if(arr[l]<arr[r]) l++;
            else r--;
        }
        return ans;
    }
};
