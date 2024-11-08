class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int>a1, a2;
        
        int i=0;
        while(i<arr.size()){
            a1.push_back(arr[i++]);
            if(i<arr.size()){
                a2.push_back(arr[i++]);
            }
        }
        
        reverse(a1.begin(), a1.end());
        reverse(a2.begin(), a2.end());
        
        vector<int>ans;
        i=0;
        int j=0, carry=0;
        
        while(i<a1.size() && j<a2.size()){
            int digit=a1[i++]+a2[j++]+carry;
            carry=digit/10;
            digit%=10;
            
            ans.push_back(digit);
        }
        
        while(i<a1.size()){
            int digit=a1[i++]+carry;
            carry=digit/10;
            digit%=10;
            
            ans.push_back(digit);
        }
        
        while(j<a2.size()){
            int digit=a2[j++]+carry;
            carry=digit/10;
            digit%=10;
            
            ans.push_back(digit);
        }
        
        while(carry){
            int digit=carry;
            carry=digit/10;
            digit%=10;
            
            ans.push_back(digit);
        }
        
        reverse(ans.begin(), ans.end());
        i=0;
        while(i<ans.size() && ans[i]==0) i++;
        
        if(i==ans.size()) return "0";
        
        string res="";
        while(i<ans.size()){
            res+='0'+ans[i++];
        }
        
        return res;
    }
};
