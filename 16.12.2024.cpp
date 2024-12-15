class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size(), m=b.size();
        if(n>m) return kthElement(b, a, k);
        
        int lo=max(0, k-m), hi=min(n, k);
        while(lo<=hi){
            int mid1=(lo+hi)/2;
            int mid2=k-mid1;
            
            int l1, r1, l2, r2;
            if(mid1==0){
                l1=INT_MIN;
            }
            else{
                l1=a[mid1-1];
            }
            
            if(mid1==n){
                r1=INT_MAX;
            }
            else{
                r1=a[mid1];
            }
            
            if(mid2==0){
                l2=INT_MIN;
            }
            else{
                l2=b[mid2-1];
            }
            
            if(mid2==m){
                r2=INT_MAX;
            }
            else{
                r2=b[mid2];
            }
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            
            if(l1>r2){
                hi=mid1-1;
            }
            else{
                lo=mid1+1;
            }
        }
        return 0;
        
    }
};
