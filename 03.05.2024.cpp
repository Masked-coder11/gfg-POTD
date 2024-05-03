class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      vector<int>ans;
      int level=0;
      queue<Node*>q;
      q.push(root);
      
      while(!q.empty()){
          int n=q.size();
          for(int i=0;i<n;i++){
              Node* node=q.front(); q.pop();
              if(level==k) ans.push_back(node->data);
              
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
          }
          level++;
      }
      return ans;
    }
};
