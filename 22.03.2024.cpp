*/

class Solution
{
    public:
    void solve(Node*root, map<int,int>&mp, int level){
        if(!root) return;
        mp[level]+=root->data;
        
        solve(root->left, mp, level+1);
        solve(root->right, mp, level);
        
        return;
    }
    
    vector <int> diagonalSum(Node* root) {
        // Add your code here
        map<int,int>mp;
        solve(root, mp, 0);
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
