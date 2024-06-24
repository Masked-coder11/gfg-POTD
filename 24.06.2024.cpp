class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(2*n < q){
            return 0ll;
        }
        else if(q<=n){
            return q-1;
        }
        else{
            return 2*n-q+1;
        }
    }
};
