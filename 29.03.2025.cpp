class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({deadline[i], profit[i]});
        }
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>, greater<int>>pq;
        int curr=0, points=0;
        for(int i=0;i<n;i++){
            if(v[i].first > curr){
                curr++;
                points+=v[i].second;
                pq.push(v[i].second);
            }
            else if(v[i].second > pq.top()){
                points-=pq.top();
                pq.pop();
                points+=v[i].second;
                pq.push(v[i].second);
            }
        }
        return {curr, points};
        
    }
};
