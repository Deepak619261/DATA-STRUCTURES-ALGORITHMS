class Solution {
public:
    int minAddToMakeValid(string s) {
        int opencnt=0;
        int closecnt=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                opencnt++;
            }
            else{
                if(opencnt>0){
                    opencnt--;
                }
                else{
                    closecnt++;
                }
            }
        }
        return opencnt+closecnt;
    }
};