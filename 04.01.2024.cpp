class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        int one=0, two=0, common;
        for(int i=0;i<N;i++){
            two =two | (one & arr[i]);
            one =one ^ arr[i];
            
            common=one & two;
            
            one = one & (~common);
            two = two & (~common);
        }
        
        return one;
        
    }
};
