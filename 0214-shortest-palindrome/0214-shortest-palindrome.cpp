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
    string shortestPalindrome(string s) {

    if(s=="" || s.size()==1) return s;
      string rev=s;
      reverse(rev.begin(),rev.end());
      
      vector<int>lpsarr=findpre(s+'$'+rev);


      
      int index=lpsarr.back();

      


      string toadd=s.substr(index);
      reverse(toadd.begin(),toadd.end());
      return toadd+s;
      return s;
    }
};