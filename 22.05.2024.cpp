class Solution {
  public:
    bool check(double mid, vector<int>&arr, int k){
        int n=arr.size();
        int count=0;
        for(int i=1;i<n;i++){
            int dist=arr[i]-arr[i-1];
            if(dist<=mid){
                continue;
            }
            else{
                count+=int(dist/mid);
            }
        }
        return count<=k;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        double lo=0.0;
        double hi=0.0;
        for(int i=1;i<n;i++){
            if(hi<stations[i]-stations[i-1]){
                hi=stations[i]-stations[i-1];
            }
        }
        double ans=hi;
        while(hi-lo>1e-9){
            double mid= (hi-lo)/2.0 + lo;
            if(check(mid, stations, k)){
                ans=mid;
                hi=mid;
            }
            else{
                lo=mid;
            }
        }
        return ans;
    }
};
