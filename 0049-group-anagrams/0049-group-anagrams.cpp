class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //  better appraoch 
        unordered_map<string,vector<string>>mpp;

        for(auto it:strs){
            string srted=it;
            sort(srted.begin(),srted.end());
            if(mpp.contains(srted)){
                mpp[srted].push_back(it);
            }else{
                mpp[srted].push_back(it);
            }
        }

        vector<vector<string>>ans;

        for(auto it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};