// User function Template for C++

// Function to find the minimum element in the given BST.

class Solution {
public:   
    int minValue(Node* root) {
        // Code here
        if(!root) return -1;
        
        while(root->left != NULL){
            root=root->left;
        }
        
        return root->data;
    }
};
