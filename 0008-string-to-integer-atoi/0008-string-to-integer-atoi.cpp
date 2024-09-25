class Solution {
public:
    int myAtoi(string s) {
        bool isNegative=false;
        int first=0;
       
        

        //  go untill you find a digit 

        while(isspace(s[first])){
            first++;
        }
        if(s[first]=='-' || s[first]=='+'){
            if(s[first]=='-') isNegative=true;
            first++;
        }
        int i=first;

        

        double ans=0;
        

        while(s[i]>='0' && s[i]<='9' && i<s.size()){
            ans=ans*10+(s[i]-'0');
            i++;
        }

        if(isNegative){
            ans=-ans;
        }
        if(ans>INT_MAX) return INT_MAX;
        if(ans<INT_MIN) return INT_MIN;
        return ans;
    }
};