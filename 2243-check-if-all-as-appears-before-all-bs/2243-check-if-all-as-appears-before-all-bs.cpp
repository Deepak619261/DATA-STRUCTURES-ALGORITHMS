class Solution {
public:
    bool checkString(string s) {
        bool isb=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                isb=true;
            }
            if(s[i]=='a' && isb)return false;
        }

        return true;
    }
};