class Solution {
  public:
    unordered_map<Node*, Node*>mp;
  
    Node* cloneGraph(Node* node) {
        // code here
        if(node==NULL) return NULL;
        if(mp.find(node)!=mp.end()){
            return mp[node];
        }
        else{
            Node* newNode=new Node(node->val);
            mp[node]=newNode;
            for(auto it:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(it));
            }
            
        }
        return mp[node];
        
    }
};
