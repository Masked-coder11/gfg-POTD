class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int dist(Node* root, int a, int d){
        if(root==NULL){
            return -1;
        }
        if(root->data==a){
            return d;
        }
        
        int left=dist(root->left, a, d+1);
        int right= dist(root->right, a, d+1);
        
        if(left!=-1) return left;
        if(right!=-1) return right;
        
        return -1;
    }
    
    Node* findLCA(Node*root, int a, int b){
        if(root==NULL) return NULL;
        if(root->data==a || root->data==b) return root;
        
        Node* left= findLCA(root->left, a, b);
        Node* right= findLCA(root->right, a, b);
        
        if(left==NULL) return right;
        if(right==NULL) return left;
        
        return root;
        
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca= findLCA(root, a, b);
        
        int A= dist(root, a, 0);
        int B= dist(root, b, 0);
        int C= dist(root, lca->data, 0);
        
        return A+B-2*C;
    }
};
