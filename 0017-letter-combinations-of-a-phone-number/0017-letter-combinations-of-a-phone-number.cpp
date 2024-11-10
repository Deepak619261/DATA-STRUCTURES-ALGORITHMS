class Solution {
    void solve(string digits,vector<string>&ans,string str[],int index,string store){
         if(index==digits.size()){
            if(store.size()==digits.size()){
            ans.push_back(store);
            }  
            return;
         }

         int num=digits[index]-'0';

         for(int i=0;i<str[num].size();i++){
            store+=str[num][i];
            solve(digits,ans,str,index+1,store);
            store.pop_back();
         }
    }
public:
    vector<string> letterCombinations(string digits) {
        // we have to create a map for this question 

        string str[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits=="") return ans;
        solve(digits,ans,str,0,"");

        return ans;
        
    }
};