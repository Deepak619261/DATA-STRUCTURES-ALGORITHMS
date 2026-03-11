class Solution {
public:
    int minOperations(string s) {

        //  star thinking from the base case -> for string length one 
        // string len ==2 , if the string is not sorted then its impossible because we need to sort the entire string 
        // dry run some cases 
        // only where the strict condition that minimum char doesn't exists in any proper prefix AND max char doesn't exists in any proper suffix , then we return 3 else 2 
        //   proper prefix means from o to n-1 except only the last index 
        //  vice versa the proper suffix
        int n=s.size();
        string str=s;
        sort(str.begin(),str.end());
        if(s==str)return 0;

        if(n==2){
            if(s==str)return 0;
            return -1;
        }
        
        if(str[0]==s[0] || s[n-1]==str[n-1])return 1;

        // if(str[0]==s[n-1] && str[n-1]==s[0])return 3;
        char mn=str[0];
        char mx=str[n-1];

        for(int i=0;i<s.size();i++){
             if(s[i]==mn && i!=n-1)return 2;
             if(s[i]==mx && i!=0)return 2;
        }

        return 3;
    }
};