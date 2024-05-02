/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    Node* solve(vector<int>&A, int& ind){
        if(A[ind]==-1){
            ind++;
            return NULL;
        }
        Node* root= new Node(A[ind]);
        ind++;
        root->left=solve(A, ind);
        root->right=solve(A, ind);
        
        return root;
    }
    
    void pre(Node* root, vector<int>&ans){
        if(root==NULL){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        pre(root->left,ans);
        pre(root->right,ans);
        
        return;
    }
    
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
        pre(root, ans);
        
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int ind=0;
       return solve(A,ind);
    }

};
