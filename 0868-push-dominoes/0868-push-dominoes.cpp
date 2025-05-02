class Solution {
public:
    string pushDominoes(string dominoes) {
        // watched the solution from solutions section 
        // so we can have following cases -> lets think from the pov of being a domino in a middle
        // if i am a domino and on my left side a L and right R , i will as its 
        // if i am a domino -> L . L || R . R -> R/L
        // if i am a domino -> R . L -> no effect -> even length will be equal of the closeset 
        string s='L'+dominoes+'R';

        int first=0;
        int second=1;
        string ans="";

        while(second<s.size() && first<s.size()){
            if(s[second]=='.'){
                second++;
                continue;
            }

            int len=second-first-1;

            if(first>0){
                ans+=s[first];
            }

            if(s[first]==s[second]){
                ans+=string(len,s[first]);
            }
            else if(s[first]=='L' && s[second]=='R'){
                ans+=string(len,'.');
            }
            else{
                if(len%2==0){
                    ans+=string(len/2,s[first]);
                    ans+=string(len/2,s[second]);
                }
                else{
                    ans+=string(len/2,s[first]);
                    ans+='.';
                    ans+=string(len/2,s[second]);
                }
            }
            first=second;
            second++;
        }

        return ans;
    }
};