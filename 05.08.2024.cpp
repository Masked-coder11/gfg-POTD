//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int, int>mp;
        queue<pair<int, Node*>>q;
        q.push({0, root});
        
        while(!q.empty()){
            int level=q.front().first;
            Node* node=q.front().second;
            mp[level]=node->data;
            q.pop();
            
            if(node->left){
                q.push({level-1, node->left});
            }
            if(node->right){
                q.push({level+1, node->right});
            }
        }
        
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
        
    }
};
