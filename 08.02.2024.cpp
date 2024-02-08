/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        if(root==NULL) return true;
        
        queue<Node* > q;
        q.push(root);
        int level=0;
        int leaf=-1;
        while(!q.empty()){
            int n=q.size();
            level++;
            
            for(int i=0;i<n;i++){
                Node* curr=q.front();
                q.pop();
                
                if(!curr->left && !curr->right){
                    //i have encountered a leaf node
                    if(leaf==-1){
                        leaf=level;
                    }
                    else if(leaf!=level){
                        return false;
                    }
                }
                
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
            
            
        }
        return true;
    }
};
