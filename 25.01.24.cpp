//User function Template for C++
class Solution{   
public:
    int bfs(int source, int dest){
        //let us make an array to store which numbers are prime
        vector<int>prime(10000,1);
        prime[1]=0;
        for(int i=2;i<=9999;i++){
            if(prime[i]){
                for(int j=2;j*i<=9999;j++){
                    prime[j*i]=0;
                }
            }
        }
        
        //bfs;
        vector<int>vis(10000,0);
        vector<int>arr(10000,-1);
        queue<int>q;
        q.push(source);
        vis[source]=1;
        arr[source]=0;
        while(!q.empty()){
            int value=q.front();
            q.pop();
            
            //finding all the connected numbbers
            string s= to_string(value);
            for(int i=0;i<=3;i++){
                for(char ch='0';ch<='9';ch++){
                    if(ch==s[i] || (ch=='0' && i==0)){
                        continue;
                    }
                    string nxt=s;
                    nxt[i]=ch;
                    
                    int n=stoi(nxt);
                    if(prime[n] && vis[n]==0){
                        vis[n]=1;
                        arr[n]=arr[value]+1;
                        q.push(n);
                    }
                }
            }
        }
        return arr[dest];
    }
    
    int solve(int Num1,int Num2)
    {   
      //code here
      return bfs(Num1, Num2);
    }
};
