//User function Template for C++

class Solution{
public:
  //Function to find the parent of a node in the union-find data structure.
  string find(string s, map<string, string> &p)
  {
    //If the parent of the node is the node itself, we return the node.
    //Otherwise, we recursively find the parent of the parent until we reach the node whose parent is itself.
    return p[s] == s ? s : find(p[s], p);
  }
  
  //Function to merge the accounts using union-find data structure.
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    //Creating maps for owner, parent, and unions.
    map<string, string> owner;
    map<string, string> parents;
    map<string, set<string>> unions;
    
    //Looping through all the accounts to initialize the maps.
    for (int i = 0; i < accounts.size(); i++)
    {
      //Setting the parent of each email as the email itself.
      //Setting the owner of each email as the first email in the account.
      for (int j = 1; j < accounts[i].size(); j++)
      {
        parents[accounts[i][j]] = accounts[i][j];
        owner[accounts[i][j]] = accounts[i][0];
      }
    }
    
    //Looping through all the accounts to merge the emails.
    //Merging is done by finding the parent of each email and updating the parent of all emails in the account to the same parent.
    for (int i = 0; i < accounts.size(); i++)
    {
      string p = find(accounts[i][1], parents);
      for (int j = 2; j < accounts[i].size(); j++)
        parents[find(accounts[i][j], parents)] = p;
    }
    
    //Looping through all the accounts to group the emails by their parent.
    //We add each email to the set of emails for its parent.
    for (int i = 0; i < accounts.size(); i++)
      for (int j = 1; j < accounts[i].size(); j++)
        unions[find(accounts[i][j], parents)].insert(accounts[i][j]);

    //Creating the result vector of vectors.
    //For each group of emails (union), we convert the set of emails to a vector and insert the owner as the first element of the vector.
    vector<vector<string>> ans;
    for (pair<string, set<string>> p : unions)
    {
      vector<string> res(p.second.begin(), p.second.end());
      res.insert(res.begin(), owner[p.first]);
      ans.push_back(res);
    }
    //Returning the result vector of vectors.
    return ans;
  }
};
