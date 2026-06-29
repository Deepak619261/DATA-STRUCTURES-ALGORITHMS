class Solution {
    bool isalphanumeric(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        if(s.size()==0)return true;
        int start=0;
        int end=s.size()-1;

        while(start<end){
            while(start<end && !isalphanumeric(s[end])){
                end--;
            }
            while(start<end && !isalphanumeric(s[start])){
                start++;
            }
            // if(start>=s.size() || end<0)return false;
            if(tolower(s[start])!=tolower(s[end]))return false;
            start++;
            end--;
        }

        return true;
    }
};