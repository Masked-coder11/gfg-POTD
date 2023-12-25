class Solution{
  public:
  
  vector<int> findZero(vector<int>&temp, int n){
      int start=-1, end=-1, maxLength=0;
      unordered_map<int,int>mp;
      int sum=0;
      
      for(int i=0;i<n;i++){
          sum+=temp[i];
          if(temp[i]==0 && maxLength==0){
              maxLength=1;
              start=i;
              end=i;
          }
          
          if(sum==0){
              maxLength=i+1;
              start=0;
              end=i;
          }
          
          if(mp.find(sum) !=mp.end()){
              if(maxLength < i-(mp[sum])){
                  maxLength=i-(mp[sum]);
                  start=mp[sum]+1;
                  end=i;
              }
          }
          else{
              mp[sum]=i;
          }
      }
      if(maxLength==0){
          return {0, -1, -1};
      }
      else{
          return {1, start, end};
      }
  }
  
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      
      int row=a.size();
      int col=a[0].size();
      
      int f_up=-1, f_down=-1, f_right=-1, f_left=-1;
      int f_ele=0;
      
      for(int left=0;left<col;left++){
          vector<int>temp(row,0);
          for(int right=left;right<col;right++){
              for(int i=0;i<row;i++){
                  temp[i]+=a[i][right];
              }
              
              vector<int>result=findZero(temp, row);
              if(result[0]==1){
                  int up=result[1];
                  int down=result[2];
                  
                  int ele= (down-up+1)*(right-left+1);
                  
                  if(f_ele < ele){
                      f_ele = ele;
                      f_down=down;
                      f_left=left;
                      f_right=right;
                      f_up=up;
                  }
              }
              
          }
      }
      
      vector<vector<int>>ans;
      if(f_ele==0){
          return ans;
      }
      
      for(int i=f_up;i<=f_down;i++){
         vector<int>column;
         for(int j=f_left;j<=f_right;j++){
             column.push_back(a[i][j]);
         }
         ans.push_back(column);
      }
      return ans;
  }
};
