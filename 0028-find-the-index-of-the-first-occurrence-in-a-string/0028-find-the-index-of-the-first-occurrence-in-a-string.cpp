class Solution {
    vector<int>getprefix(string str){
        int m=str.size();
        vector<int>lps(m,0);


        int i=1;
        int len=0;

        while(i<m){
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
                    // lps[i]=0;
                    i++;
                }
              }
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {

        

        int i=0;
        int j=0;

        int n=haystack.size();
        int m=needle.size();


        vector<int>lps=getprefix(needle);

       while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }


            if(j==m){
                return i-j;
            }

            if(haystack[i]!=needle[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }

        }




        return -1;
        
    }
};