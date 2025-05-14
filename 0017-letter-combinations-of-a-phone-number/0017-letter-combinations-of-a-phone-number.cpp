class Solution {
    void solve(int index,vector<string>&ans,string digits,vector<string>&dict,string curr){
        if(index==digits.size()){
            if(!curr.empty()){
            ans.push_back(curr);
            }
            return;
        }

        // lets say i am at the first index 
        for(int i=0;i<dict[digits[index]-'0'].size();i++){
            solve(index+1,ans,digits,dict,curr+dict[digits[index]-'0'][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        // create the mapping 
        vector<string>dict(10);
        dict.push_back("");

        dict[2]="abc";
        dict[3]="def";
        dict[4]="ghi";
        dict[5]="jkl";
        dict[6]="mno";
        dict[7]="pqrs";
        dict[8]="tuv";
        dict[9]="wxyz";

        solve(0,ans,digits,dict,"");

        return ans;
    
       
        
    }
};