class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        
        unordered_map<string, int>mp;
        int count=0;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(count < mp[arr[i]]) count=mp[arr[i]];
        }
        
        string ans="";
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==count){
                if(ans==""){
                    ans=arr[i];
                }
                else if(arr[i] < ans){
                    ans= arr[i];
                }
            }
            
        }
        return {ans, to_string(count)};
    }
};
