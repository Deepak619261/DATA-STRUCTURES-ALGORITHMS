class Solution {
public:
    bool areNumbersAscending(string s) {
         int prev=-1;
         int currnum=-1;
         string curr="";

         for(int i=0;i<s.size();i++){
            if(s[i]==' ' && curr!=""){
                currnum=stoi(curr);
                if(currnum<=prev)return false;
                prev=currnum;
                curr="";
            }
            if(s[i]>='0' && s[i]<='9'){
                curr+=s[i];
            } 
         }

         if(curr!="" && stoi(curr)<=prev)return false;

         return true;
    }
};