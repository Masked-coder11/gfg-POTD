class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int lo=0, hi=n-1;
        int ans=arr[0];
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(abs(k-arr[mid])==abs(k-ans)){
                ans=max(ans, arr[mid]);
            }
            else if(abs(k-arr[mid])<abs(k-ans)){
                ans=arr[mid];
            }
            
            if(arr[mid]==k) return arr[mid];
            else if(arr[mid]<k) lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    } 
};
