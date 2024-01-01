
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        if(k==1){
            //kadane's algorithm
            long long int sum=0;
            long long int maxi=a[0];
            for(long long int i=0; i<n;i++){
                sum+=a[i];
                maxi=max(sum,maxi);
                if(sum<0) sum=0;
            }
            return maxi;
            
        }
        
        vector<long long int>v(n,0);
        long long int sum=0;
        v[0]=0;
        for(long long int i=0; i<n;i++){
            if(sum >=0){
                sum+=a[i];
            }
            else{
                sum=a[i];
            }
            
            if(sum<0){
                sum=0;
            }
            v[i]=sum;
        }
        
        
        sum=0;
        for(long long int i=0;i<=k-1;i++){
            sum+=a[i];
        }
        
        long long int ans=sum;
        
        long long int curr=sum-a[0]+a[k];
        long long int i=1, j=k;
        while(j<n){
            ans = max(ans, curr + v[i-1]);
            curr = curr - a[i];
            i++;
            j++;
            curr = curr + a[j];
        }
        
        
        return ans;
        
    }
};
