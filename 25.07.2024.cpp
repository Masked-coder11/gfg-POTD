/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* solve(vector<int>&nums, int lo, int hi){
        if(lo>hi) return NULL;
        if(lo==hi) return new Node(nums[lo]);
        int mid=(lo+hi)/2;
        Node* root= new Node(nums[mid]);
        root->left=solve(nums, lo, mid-1);
        root->right=solve(nums, mid+1, hi);
        
        return root;
    }
  
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n=nums.size();
        return solve(nums, 0, n-1);
        
    }
};
