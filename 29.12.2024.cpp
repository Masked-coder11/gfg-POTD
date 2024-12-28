class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j]) i++;
            else j++;
            
            while(i>0 && i<a.size() && a[i]==a[i-1]) i++;
            while(j>0 && j<b.size() && b[j]==b[j-1]) j++;
        }
        return ans;
    }
};
