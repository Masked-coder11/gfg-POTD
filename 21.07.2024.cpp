// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n=arr.size();
        int neg=0, zero=0, negative=-1e9;
        long long int prod=1;
        int mod=1e9+7;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0) zero++;
            else if(arr[i]<0){
                neg++;
                negative=max(negative, arr[i]);
                prod*=arr[i];
            }
            else{
                prod*=arr[i];
            }
            prod%=mod;
        }
        
        if(zero==n) return 0;
        if(neg==1 && zero==n-1) return 0;
        if(neg%2==0) return prod;
        if(neg%2==1) prod=prod/negative;
        
        return prod;
    }
};
