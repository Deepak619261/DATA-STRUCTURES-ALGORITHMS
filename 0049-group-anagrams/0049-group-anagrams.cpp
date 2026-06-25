class Solution {

    string CovertToFrequencySignature(string str){
        vector<int>freq(26,0);

        for(auto it:str){
            freq[it-'a']++;
        }
        string ans="";
        for(int i=0;i<26;i++){
           ans+=(to_string(freq[i]))+'#';
        }

        return ans;

        //  time complexity -> O(26*k)
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       // core idea is that frequency array of the same 
       // so instead of sorting we can just keep the ferq array mapping , but in unordered_map , we can't keep something like vector<int> -> vector<string> 
       // but we can keep someting like that in ordered_map , but time compelixty reaches to the log same as the sorting one so no benefit doing that 
       // another thing to distinct the difference between array like 1,0,1 and 11,0,1 we use # inbetween to separate and we convert the fre array to string 

       unordered_map<string,vector<string>>mpp;

       vector<vector<string>>ans;
       

       for(auto it:strs){
        //   cout<<" freq signature for "<<it<<" is"<<CovertToFrequencySignature(it)<<endl;
          string signature=CovertToFrequencySignature(it);
          mpp[signature].push_back(it);
       }


       for(auto it:mpp){
          ans.push_back(it.second);
       }

       return ans;

    }
};