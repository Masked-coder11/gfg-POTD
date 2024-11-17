class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d%=n;
        
        reverse(arr.begin()+d, arr.end());
        reverse(arr.begin(), arr.begin()+d);
        
        reverse(arr.begin(), arr.end());
        
        return;
        
    }
};
