class Solution {
    bool isPrefixAndSuffix(string str1, string str2){
        if(str1.size()>str2.size())return false;

        int ind1=str2.find(str1);
        if(ind1==-1)return false;

        int n=str1.size();
        string check=str2.substr(str2.size()-n, n);
        return (ind1==0 && check==str1);
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int count=0;
        
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    count++;
                }
            }
        }

        return count;
    }
};