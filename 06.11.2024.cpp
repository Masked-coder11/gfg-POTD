class Solution {
  public:
    int ans=0;
    
    void traverse(Node* root, int curr){
        if(!root) return;
        
        curr=curr*10+root->data;
        
        if(!root->left && !root->right){
            ans+=curr;
        }
        
        traverse(root->left, curr);
        traverse(root->right, curr);
        
        return;
    }
  
    int treePathsSum(Node *root) {
        // code here.
        traverse(root, 0);
        return ans;
    }
};
