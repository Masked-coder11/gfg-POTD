// User function Template for C++

class Solution {
  public:
    void printArr(int n, int arr[]) {
        // Your code for printing array here
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void setToZero(int n, int arr[]) {
        // Use memset to set arr to zero
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
    }

    void xor1ToN(int n, int arr[]) {
        // Xor arr[i]^i
        for(int i=0;i<n;i++){
            arr[i]=arr[i]^i;
        }
    }
};
