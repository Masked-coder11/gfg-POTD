class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<arr.size();i++){
            v.push_back({abs(arr[i]-brr[i]), {arr[i], brr[i]}});
        }
        sort(v.rbegin(), v.rend());
        
        long long ans=0;
        for(int i=0;i<v.size();i++){
            if(x==0){
                ans+=v[i].second.second;
            }
            else if(y==0){
                ans+=v[i].second.first;
            }
            else{
                if(v[i].second.first > v[i].second.second){
                    x--;
                    ans+=v[i].second.first;
                }
                else{
                    y--;
                    ans+=v[i].second.second;
                }
            }
        }
        return ans;
    }
};
