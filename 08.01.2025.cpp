class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n=arr.size(), ans=0;
        for(int k=n-1;k>=0;k--){
            int i=0, j=k-1;
            while(i<j){
                if(arr[i]+arr[j]>arr[k]){
                    ans+=j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};
