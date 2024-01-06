class Solution {
  public:
    bool check(int arr[], int N, int K, int mid){
        int sum=0;
        int count=0;
        
        for(int i=0;i<N;i++){
            if(arr[i]>mid){
                return false;
            }
            
            sum+=arr[i];
            if(sum > mid){
                count++;
                sum=arr[i];
            }
        }
        count++;
        
        if(count > K){
            return false;
        }
        return true;
    }
  
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int mini=0, maxi=0;
        for(int i=0 ;i<N; i++){
            mini = max(mini, arr[i]);
            maxi +=arr[i];
        }
        
        int ans=maxi;
        while(mini <= maxi){
            int mid = (mini+maxi)/2;
            if(check(arr, N, K, mid)){
                ans=mid;
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
        }
        
        return ans;
    }
};
