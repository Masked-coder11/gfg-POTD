class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<vector<int>>v;
        
        //{end, start, meeting}
        
        for(int i=0;i< N;i++){
            v.push_back({F[i], S[i], i+1});
        }
        
        sort(v.begin(), v.end());
        
        vector<int>ans;
        int t=-1;
        
        
        for(int i=0;i<N;i++){
            if( v[i][1] > t){
                ans.push_back(v[i][2]);
                t=v[i][0];
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};
