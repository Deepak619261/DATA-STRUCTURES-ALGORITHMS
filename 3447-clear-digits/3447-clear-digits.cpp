class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++){
           if(s[i]>='0' && s[i]<='9' && !isdigit(ans.back())){
             ans.pop_back();
           }
           else{
            ans+=s[i];
           }
        }

        return ans;
    }
};