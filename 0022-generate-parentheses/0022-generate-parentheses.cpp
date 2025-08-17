class Solution {
    void solve(int open,int close, vector<string>&result,string &str){
    if(open==0 && close==0){
        result.push_back(str);
        return;
    }

    if(close==open){
        str+='(';
        solve(open-1,close,result,str);
        str.pop_back();
    }
    else if(open==0){
        str+=')';
        solve(open,close-1,result,str);
        str.pop_back();
    }
    // else if(close==0){
    //     str+='(';
    //     solve(open-1,close,result,str);
    //     str.pop_back();
    // }
    else{
        str+='(';
        solve(open-1,close,result,str);
        str.pop_back();

        str+=')';
        solve(open,close-1,result,str);
        str.pop_back();
    }
   }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int opencnt=n;
        int closecnt=n;
        string str="";
        solve(opencnt,closecnt,ans,str);
        return ans;
    }
};