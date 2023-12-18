class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        
        int ans=0;
        
        int sub=0;
        int val=1;
        
        int i=0, j=N-1;
        
        while(i<=j){
            int number= (i+1)*N - (sub)*2;
            
            if(number%2 == 1){
                if(i==j){
                    ans = ans^A[i];
                }
                else{
                    ans= ans^ A[i] ^ A[j];
                }
            }
            
            sub=sub+val;
            val++;
            
            i++;
            j--;
            
        }
        
        return ans;
    }
};
