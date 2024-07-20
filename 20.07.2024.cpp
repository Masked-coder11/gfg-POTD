class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(root==NULL) return NULL;
        
        root->left= RemoveHalfNodes(root->left);
        root->right= RemoveHalfNodes(root->right);
        
        if(!root->left && !root->right) return root;
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        
        return root;
        
    }
};
