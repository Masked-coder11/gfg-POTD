class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n=arr.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        
        int i=0;
        while(i<=k){
            pq.push(arr[i++]);
        }
        
        int ptr=0;
        while(ptr<n){
            arr[ptr++]=pq.top();
            pq.pop();
            
            if(i<n) pq.push(arr[i++]);
        }
        return;
        
    }
};
