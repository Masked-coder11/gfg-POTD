class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        n--;
        int prev=1;
        vector<int>res;
        res.push_back(prev);
        for(int i=1;i<=n;i++){
            int curr  = prev*(n-i+1)/i;
            res.push_back(curr);
            prev=curr;
        }
        return res;
    }
};
