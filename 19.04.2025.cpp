class Node{
public:
  Node* one;
  Node* zero;
  
  Node(){
      one=NULL;
      zero=NULL;
  }
};

class Trie{
public:
  Node* root;
  
  Trie(){
      root= new Node();
  }
  
  void insert(int n){
      Node* temp=root;
      for(int i=31;i>=0;i--){
          int bit= (n>>i)&1;
          if(bit==0){
              if(!temp->zero){
                  temp->zero = new Node();
              }
              temp=temp->zero;
          }
          else{
              if(!temp->one){
                  temp->one = new Node();
              }
              temp=temp->one;
          }
      }
  }
  
  int findMax(int n){
      int res=0;
      Node* temp=root;
      
      for(int i=31;i>=0;i--){
          int bit = (n>>i)&1;
          if(bit==0){
              if(temp->one){
                  temp=temp->one;
                  res+=(1<<i);
              }
              else{
                  temp=temp->zero;
              }
          }
          else{
              if(temp->zero){
                  temp=temp->zero;
                  res+=(1<<i);
              }
              else{
                  temp=temp->one;
              }
          }
      }
      return res;
  }
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        int n=arr.size();
        Trie* trie= new Trie();
        trie->insert(arr[0]);
        int res=0;
        for(int i=1;i<n;i++){
            res=max(res, trie->findMax(arr[i]));
            trie->insert(arr[i]);
        }
        return res;
        
    }
};
