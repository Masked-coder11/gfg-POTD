class Trie {
  public:
  
  bool end;
  vector<Trie*>children;

    Trie() {
        // implement Trie
        end=false;
        children.resize(26, NULL);
    }

    void insert(string &word) {
        // insert word into Trie
        Trie * root= this;
        for(auto it:word){
            int idx=it-'a';
            if(!root->children[idx]){
                root->children[idx]= new Trie();
            }
            root=root->children[idx];
        }
        root->end=true;
    }

    bool search(string &word) {
        // search word in the Trie
        Trie* root=this;
        for(auto it:word){
            int idx=it-'a';
            if(!root->children[idx]){
                return false;
            }
            root=root->children[idx];
        }
        return root->end;
        
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Trie* root=this;
        for(auto it:word){
            int idx=it-'a';
            if(!root->children[idx]){
                return false;
            }
            root=root->children[idx];
        }
        return true;
    }
};
