
class Solution{
  public:
  map<int,int>mp;
  void preorder(Node* node, int level){
      if(node!=NULL){
          mp[level]+=node->data;
          
          preorder(node->left, level-1);
          preorder(node->right, level+1);
          
          return;
      }
  }
  
    vector <int> verticalSum(Node *root) {
        // add code here.
        preorder(root, 0);
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
