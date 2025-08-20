class Solution {
    void solve(int index, vector<string>&ans,vector<string>&mpp , string str, string digits){
    if(index==digits.size()){
      ans.push_back(str);
      return;
    }

int x=digits[index]-'0';

    for(int i=0;i<mpp[x].size();i++){
       solve(index+1,ans,mpp,str+mpp[x][i],digits);
    }

}
public:
    vector<string> letterCombinations(string digits) {
         //declare a vector<string 
         vector<string>mpp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

         vector<string>ans;
        if(digits.empty())return ans;
         solve(0,ans,mpp,"",digits);
         return ans;
    }
};