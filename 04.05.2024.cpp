/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    
    Node* solve(int in[], int pos[], int inStart, int inEnd, int posStart, int posEnd){
        if(inStart>inEnd) return NULL;
        if(inStart==inEnd){
            return new Node(in[inStart]);
        }
        Node* root= new Node(pos[posEnd]);
        int ind = -1;
        for(int i=inStart;i<=inEnd;i++){
            if(in[i]==pos[posEnd]){
                ind=i;
                break;
            }
        }
        int left=ind-inStart;
        int right=inEnd-ind;
        
        root->left=solve(in, pos, inStart,ind-1, posStart, posStart+left-1);
        root->right=solve(in, pos, ind+1, inEnd, posEnd-right, posEnd-1);
        
        return root;
    }
    

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        return solve(in, post, 0, n-1, 0, n-1);
        
    }
};
