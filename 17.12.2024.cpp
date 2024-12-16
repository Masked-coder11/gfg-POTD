class Solution {
  public:
    bool check(vector<int>&stalls, int k, int mid){
        int count=0, prev=-1;
        for(int i=0;i<stalls.size();i++){
            if(prev==-1 || stalls[i]-prev>=mid){
                count++;
                prev=stalls[i];
            }
        }
        return count>=k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n=stalls.size();
        int lo=0, hi=stalls[n-1]-stalls[0];
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(stalls, k, mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};
