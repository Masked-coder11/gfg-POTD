// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
  
  long long int merge(vector<int>&arr, long long low, long long mid, long long high){
        long long temp[high-low+1];
        long long int k=0;
        long long int i=low;
        long long int j=mid+1;
        long long int inv=0;
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                inv+= mid-i +1;
                temp[k++]=arr[j++];
            }
        }
        
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        
        while(j<=high){
            temp[k++]=arr[j++];
        }
        
        for(int x=low; x<=high; x++){
            arr[x]=temp[x-low];
        }
        
        return inv;
    }
    
    long long int mergeSort(vector<int>&arr, long long int low, long long int high){
        if(low>=high) return 0;
        long long int inv=0;
        
        long long mid= (low+high)/2;
        
        inv += mergeSort(arr, low, mid);
        inv += mergeSort(arr, mid+1, high);
        inv += merge(arr, low, mid, high);
        
        return inv;
    }
    
    long long int inversionCount(vector<int>&arr, long long N)
    {
        // Your Code Here
        
        long long int ans= mergeSort(arr, 0, N-1);
        
        return ans;
        
        
    }
    void inorder(Node*root, vector<int>&arr){
        if(root){
            inorder(root->left, arr);
            arr.push_back(root->data);
            inorder(root->right, arr);
        }
        return;
    }

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        // store inorder traversal
        vector<int>arr;
        inorder(root, arr);
        
        // i just want to retun count inversion of arr
        long long N=n;
        return int(inversionCount(arr, N));
        
        
    }
};
