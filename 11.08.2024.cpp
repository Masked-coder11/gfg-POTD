

class Solution 
{
    public:
    static bool comp(Job j1, Job j2){
        return j1.dead < j2.dead;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comp);
        int curr=0, points=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0;i<n;i++){
            if(arr[i].dead>curr){
                points+=arr[i].profit;
                pq.push(arr[i].profit);
                curr++;
            }
            else{
                if(arr[i].profit > pq.top()){
                    points-=pq.top();
                    pq.pop();
                    
                    points+=arr[i].profit;
                    pq.push(arr[i].profit);
                }
            }
        }
        return {curr, points};
        
        
    } 
};
