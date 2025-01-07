class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int ans=0, i=0, j=arr.size()-1;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum<target) {i++;}
            else if(sum>target) {j--;}
            else{
                int ele1=arr[i], ele2=arr[j];
                int count1=0, count2=0;
                
                while(i<=j && arr[i]==ele1){
                    i++;
                    count1++;
                }
                
                while(i<=j && arr[j]==ele2){
                    j--;
                    count2++;
                }
                
                if(ele1==ele2){
                    ans+=count1*(count1-1)/2;
                }
                else{
                    ans+=count1*count2;
                }
            }
        }
        return ans;
    }
};
