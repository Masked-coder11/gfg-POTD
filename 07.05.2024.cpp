vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int>ans;
    stack<int>st;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front(); q.pop();
        st.push(node->data);
        
        if(node->right){
            q.push(node->right);
        }
        if(node->left){
            q.push(node->left);
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}
