class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<int>arr(n+1,0);
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int j=i-1;
            if(j>=0 && arr[j]==0){
                arr[i]=1;
            }
            j=i-x;
            if(j>=0 && arr[j]==0){
                arr[i]=1;
            }
            j=i-y;
            if(j>=0 && arr[j]==0){
                arr[i]=1;
            }
        }
        return arr[n];
    }
};
