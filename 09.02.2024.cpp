/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
    bool f(Node* root){
        if(root==NULL) return true;
        if(!root->left && !root->right) return true;
        
        bool left=true;
        bool right=true;
        
        int sum=0;
        if(root->left !=NULL){
            sum+=root->left->data;
            if(f(root->left)==false) return false;
        }
        if(root->right !=NULL){
            sum+=root->right->data;
            if(f(root->right)==false) return false;
        }
        
        return root->data==sum;
        
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     return f(root);
     
    }
};
