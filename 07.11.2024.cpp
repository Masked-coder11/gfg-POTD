class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        int sum=0;
        for(auto it:arr) sum+=it;
        
        int curr=0, first=-1, second=-1;
        
        int ptr=0;
        while(ptr<arr.size()){
            curr+=arr[ptr];
            
            if(curr*3==sum){
                first=ptr;
                ptr++;
                break;
            }
            else if(curr*3>sum){
                return {-1,-1};
            }
            else{
                ptr++;
            }
        }
        
        curr=0;
        while(ptr<arr.size()){
            curr+=arr[ptr];
            if(curr*3==sum){
                second=ptr;
                ptr++;
                break;
            }
            else if(curr*3 > sum){
                return {-1,-1};
            }
            else{
                ptr++;
            }
            
        }
        
        curr=0;
        while(ptr<arr.size()){
            curr+=arr[ptr];
            ptr++;
        }
        if(curr*3==sum){
            return {first, second};
        }
        else{
            return {-1,-1};
        }
    }
};
