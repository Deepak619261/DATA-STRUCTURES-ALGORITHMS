class Solution {
public:
    string frequencySort(string s) {
        //  going with bucket sort approach 
        //  steps 
        // 1. store the frequency of the characters in map 
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        // 2. create a vector of string/element/chars with size of max frequency element 
        int max_freq=0;
        for(auto it:mpp){
            max_freq=max(max_freq,it.second);
        }
        // 3. traverse throught the map and store the chars at the indices as their frequency 
        vector<vector<char>>buckets(max_freq+1);

        for(auto &it : mpp){
            buckets[it.second].push_back(it.first);
        }

        //  traverse throught the bucket list and create the ans string 
        string ans="";
        for(int i=max_freq;i>0;i--){
            for(auto it: buckets[i]){
                string str(i,it);
                ans+=str;
            }
        }

        return ans;

    }
};