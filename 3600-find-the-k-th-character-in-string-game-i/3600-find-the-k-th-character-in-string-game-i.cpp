class Solution {
    void solve(string &ans,int k){
        if(ans.size()>=k){
            return;
        }

        int len=ans.size();

        for(int i=0;i<len;i++){
            if(ans[i]=='z'){
                ans+='a';
            }
            else{
                char ch=ans[i];
                ch=ch+1;
                ans+=ch;
            }
        }
        solve(ans,k);
    }
public:
    char kthCharacter(int k) {
        string ans="a";
        solve(ans,k);
        return ans[k-1];
    }
};