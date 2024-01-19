class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        vector<vector<int>>ans;
        unordered_map<int,int>mp; //to store frequency;
        vector<int>top(K+1,-1);
        
        for(int i=0;i<N;i++){
            vector<int>temp;
            
            mp[arr[i]]++;
            top[K]=arr[i];
            
            //trying to find first occurrence of current element
            int ind=-1;
            for(int j=0;j<=K;j++){
                if(top[j]==arr[i]){
                    ind=j;
                    break;
                }
            }
            
            for(int j=ind-1;j>=0;j--){
                if(mp[top[j]] < mp[top[j+1]]){
                    swap(top[j], top[j+1]);
                }
                
                else if(mp[top[j]]==mp[top[j+1]] && top[j]>top[j+1]){
                    swap(top[j], top[j+1]);
                }
                else{
                    break;
                }
            }
            for(int j=0;j<K;j++){
                if(top[j]==-1){
                    break;
                }
                temp.push_back(top[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
