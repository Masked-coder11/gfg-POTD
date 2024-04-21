//User function template for C++

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here
        int n=arr.size();
        int start=0,end=n-1;
        for(int i=0;i<=end;i=i){
            if(arr[i]<a){
                swap(arr[i], arr[start]);
                i++;
                start++;
            }
            else if(arr[i]>b){
                int temp=arr[i];
                arr[i]=arr[end];
                arr[end--]=temp;
            }
            else{
                i++;
            }
        }
        
    }
};
