class Solution {
  public:
    void solve(Node* root, vector<int>curr, vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        
        curr.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(curr);
            return ;
        }
        
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
        
        return;
    }
  
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>curr;
        solve(root, curr, ans);
        
        
        return ans;
    }
};
