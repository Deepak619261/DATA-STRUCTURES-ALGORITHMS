class Solution {
    void solve(int count, vector<string>&ans, int openP,int closeP,string str,int n){
        if(openP>n || closeP>n || closeP>openP)return;

        if(count==2*n){
            ans.push_back(str);
            return;
        }
        
        //  at every step we only have two options either we choose a openP or a closeP
        solve(count+1,ans,openP+1,closeP,str+"(",n);
        solve(count+1,ans,openP,closeP+1,str+")",n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="(";
        solve(1,ans,1,0,curr,n);

        return ans;
    }
};