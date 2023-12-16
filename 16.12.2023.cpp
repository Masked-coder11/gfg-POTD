long long int countStr(long long int n){
    //complete the function here
    
    if(n==0) return 0;
    else if(n==1) return 3;
    else if(n==2) return 8;
    
    long long int ans=0;
    //0b 0c
    ans+=1;
    //1b 0c
    ans+=n;
    //0b 1c
    ans+=n;
    //1b 1c
    ans+=n*(n-1);
    //0b 2c
    ans+=n*(n-1)/2;
    //1b 2c
    ans+=n*(n-1)*(n-2)/2;
    
    return ans;
}
