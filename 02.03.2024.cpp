class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]==k){
                return a[i];
            }
        }
        return -1;
    }
};
