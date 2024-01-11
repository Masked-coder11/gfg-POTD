// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        int n = q.size();
        
        stack<int>st;
        for(int i=0;i<=k-1;i++){
            st.push(q.front());
            q.pop();
        }
        for(int i=0;i<k;i++){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n-k;i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
