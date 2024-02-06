//Node Structure
/*struct Node
{
	int k;
	Node *left, *right;
};*/

class Solution
{
    public:
    
    int check(Node* node, int k, int d){
        if(node->left==NULL && node->right==NULL){
            if(d==k){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int c=0;
        if(node->left){
            c =c | check(node->left,k,d+1);
        }
        if(node->right){
            c= c| check(node->right, k, d+1);
        }
        
        return c;
        
        
    }
    
    int traverse(Node* root, int k){
        if(root==NULL) return 0;
        int ans=0;
        if(check(root,k, 0)){
            ans++;
        }
        ans+=traverse(root->left,k);
        ans+=traverse(root->right,k);
        
        return ans;
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	int ans=0;
    	ans+= traverse(root, k);
    	return ans;
    }
};
