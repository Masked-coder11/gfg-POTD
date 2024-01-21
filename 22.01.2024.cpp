//User function Template for C++

/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    public:
    void solve(Node* root, int curr, int target, vector<int>path, vector<vector<int>>&ans){
        if(!root){
            return;
        }
        curr+=root->key;
        path.push_back(root->key);
        
        if(curr==target){
            ans.push_back(path);
        }
        
        solve(root->left, curr, target, path, ans);
        solve(root->right, curr, target, path, ans);
        
        return;
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>>ans;
        vector<int>path;
        int curr=0;
        
        solve(root, curr, sum, path, ans);
        
        return ans;
    }
};
