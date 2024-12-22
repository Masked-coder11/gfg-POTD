class Solution {
  public:
    bool search(vector<int>&arr, int x){
        int lo=0, hi=arr.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==x) return true;
            else if(arr[mid]<x) lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
  
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            if(mat[i][0]<=x && x<=mat[i][m-1]){
                if(search(mat[i], x)) return true;
            }
        }
        return false;
        
    }
};
