void traversal(Node*node, vector<int>&ans){
    if(node){
        if(node->left && !node->right){
            ans.push_back(node->left->data);
        }
        if(!node->left && node->right){
            ans.push_back(node->right->data);
        }
        
        traversal(node->left, ans);
        traversal(node->right, ans);
        
        return;
    }
}

vector<int> noSibling(Node* node)
{
    // code here
    vector<int>ans;
    traversal(node, ans);
    if(ans.size()==0){
        ans.push_back(-1);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
