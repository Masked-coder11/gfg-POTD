class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        int start=0, curr=0;
        for(int i=0;i<n;i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        curr=0;
        for(int i=0;i<n;i++){
            int idx=(i+start)%n;
            curr+=gas[idx]-cost[idx];
            if(curr<0) return -1;
        }
        return start;
        
    }
};
