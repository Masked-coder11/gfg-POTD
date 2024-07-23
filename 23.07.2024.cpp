/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root, vector<int>&ans){
        if(root==NULL) return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
        
        return;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>arr1, arr2, ans;
        inorder(root1, arr1);
        inorder(root2, arr2);
        
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i<arr1.size()){
            ans.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j++]);
        }
        return ans;
    }
};
