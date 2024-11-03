class Solution {

    string solve(string num){
        char prev=num[0];
        int cnt=1;

        
        string ans="";

        for(int i=1;i<num.size();i++){
           if(num[i]!=prev){
             ans+=to_string(cnt);
             cnt=1;
             ans+=prev;
             prev=num[i];
           }
           else{
             cnt++;
           }

        }

        ans+=to_string(cnt);
        ans+=prev;

        return ans;
    }
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }

        string ans="";
        string input="1";

        for(int i=1;i<n;i++){
            ans=solve(input);
            input=ans;
        }

        return ans;
    }
};