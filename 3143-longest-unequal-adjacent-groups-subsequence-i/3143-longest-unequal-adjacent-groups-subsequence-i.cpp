class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        vector<string>ans;
        vector<int>indices;
        
        int prev=-1;
        for(int i=0;i<words.size();i++){
            vector<int>temp;
            temp.push_back(i);
            prev=groups[i];
            for(int j=i+1;j<words.size();j++){
                if(groups[j]!=prev){
                    temp.push_back(j);
                    prev=groups[j];
                }
            }
            if(temp.size()>indices.size()){
                indices=temp;
            }
        }

        for(auto it:indices){
            ans.push_back(words[it]);
        }

        return ans;
    }
};