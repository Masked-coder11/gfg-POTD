class Solution
{
    public:
        int sum=0;
        
        void traversal(Node* root){
            if(root==NULL) return;
            if(root->left==NULL && root->right==NULL){
                sum+=root->data;
                return;
            }
            
            traversal(root->right);
            traversal(root->left);
            
            return ;
            
        }
        
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
             traversal(root);
             return sum;
        }
};
