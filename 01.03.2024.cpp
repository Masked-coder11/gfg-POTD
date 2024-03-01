/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       if(n==1){
           return 0;
       }
       
       int lo=0, hi=n-1;
       while(lo<=hi){
           int mid=lo+(hi-lo)/2;
           if(mid==0 && arr[mid]>=arr[mid+1]){
               return 0;
           }
           else if(mid==n-1 && arr[mid]>=arr[mid-1]){
               return n-1;
           }
           else if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]){
               return mid;
           }
           else{
               if(mid>0 && arr[mid-1]>arr[mid]){
                   hi=mid-1;
               }
               else{
                   lo=mid+1;
               }
           }
       }
    }
};
