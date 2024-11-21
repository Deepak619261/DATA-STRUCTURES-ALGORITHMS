class Solution {
    bool solve(string str){
        int s=0;
        int e=str.size()-1;

        while(s<=e){
            if(str[s]!=str[e]) return false;
            s++;
            e--;
        }

        return true;
    }
public:
    bool isPalindrome(string s) {
        string str="";

        for(int i=0;i<s.size();i++){
            if(isupper(s[i]) && s[i]>='A' && s[i]<='Z'){
                str+=tolower(s[i]);
            }

            if(s[i]>='a' && s[i]<='z' || s[i]<='9' && s[i]>='0'){
                str+=s[i];
            }
            
        }

        return solve(str);
    }
};