class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>st;
        for(auto it:a) st.insert(it);
        for(auto it:b) st.insert(it);
        
        return st.size();
    }
};
