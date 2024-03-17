/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      queue<Node*>q;
      q.push(root);
      
      vector<int>ans;
      while(!q.empty()){
          Node* node=q.front();
          q.pop();
          
          ans.push_back(node->data);
          if(node->left){
              q.push(node->left);
          }
          
          if(node->right){
              q.push(node->right);
          }
          
      }
      return ans;
    }
};
