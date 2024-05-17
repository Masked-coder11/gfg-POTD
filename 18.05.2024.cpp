class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int lo=0, hi=a.size()-1;
        
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            ans=max(ans, a[mid]);
            
            if(mid==0) lo=mid+1;
            else if(mid==a.size()-1) hi=mid-1;
            else if(a[mid]<a[mid+1]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        
        return ans;
    }
};
