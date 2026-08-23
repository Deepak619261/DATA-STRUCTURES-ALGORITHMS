class Solution {
    string binary(char c){
        int ascivalue=c;
        return (bitset<8>(ascivalue)).to_string();
    }
public:
    bool isPalindromic(string s) {
        string actual="";
        for(auto it:s){
            actual+=binary(it);
        }

        int st=0;
        int e=actual.size()-1;

        while(st<=e){
            if(actual[st++]!=actual[e--])return false;
        }

        return true;
        
    }
};