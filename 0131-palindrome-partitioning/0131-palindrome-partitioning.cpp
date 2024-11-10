class Solution {
    void solve(vector<vector<string>>&ans,vector<string>store,string &s, int index){
        if(index==s.size()){
            ans.push_back(store);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(ispalindrom(s,index,i)){
                store.push_back(s.substr(index,i-index+1));
                solve(ans,store,s,i+1);
                store.pop_back();
            }
        }
    }

    bool ispalindrom(string str,int i, int j){
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }

        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>store;
        solve(ans,store,s,0);
        return ans;
    }
};