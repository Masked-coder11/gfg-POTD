class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int val=0;
        int y=n;
        while(y>0){
            val+=pow(y%10, 3);
            y/=10;
        }
        if(val==n){
            return "Yes";
        }
        else return "No";
    }
};
