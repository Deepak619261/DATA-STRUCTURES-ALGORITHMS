class Solution {
public:
    string reverseWords(string s) {
        // reverse(s.begin(),s.end());
        
        
        // pass all the white spaces first
        int i=0;
        while(s[i]==' '){
            i++;
        } 
        string temp="";
        string ans="";
        for(i;i<s.size();i++){
            if(s[i]==' ' && temp!=""){
                ans=temp+ans;
                ans=" "+ans;
                temp="";
            }
            else if(s[i]!=' '){
                temp+=s[i];
            }
        }

        if(temp!=""){
            ans=temp+ans;
        }
        
        int len=0;
        // while(ans[len]==' '){
        //     len++;
        // }
        if(ans[0]==' ') ans.erase(0,1);
        return ans;

    }
};