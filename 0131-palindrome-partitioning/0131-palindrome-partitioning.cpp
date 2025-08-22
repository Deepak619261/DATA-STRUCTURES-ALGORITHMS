class Solution {
    bool isPalindrome(string str, int s , int e){
        while(s<=e){
            if(str[s++]!=str[e--])return false;
        }
        return true;
    }
    void solve(int index, vector<vector<string>>&ans, vector<string>temp,string s){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,ans,temp,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        //  brute force way is to check every single substring if its the palindrom or not 
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,ans,temp,s);
        return ans;
    }
};