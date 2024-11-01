class Solution {
    vector<int>findpre(string str){
         int size=str.size();
         
         vector<int>lps(size,0);
         
         int i=1;
         int len=0;
         
         while(i<size){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
         }
         
         
         return lps;
     }
public:
    string longestPrefix(string s) {
        vector<int>lps=findpre(s);

        int len=lps.back();

        return s.substr(0,len);
    }
};