class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int ptr=0, i=0;
        while(i<arr.size()){
            if(arr[i]!=0){
                arr[ptr++]=arr[i];
            }
            i++;
        }
        while(ptr<arr.size()){
            arr[ptr++]=0;
        }
        return;
    }
};
