class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }

        // for max difference we need the bigger odd freq 
        // and as min as possible even freq character 
        int oddfreq=INT_MIN;
        int evenfreq=INT_MAX;

        for(auto it:mpp){
            if(it.second%2==0){
                evenfreq=min(evenfreq,it.second);
            }
            else{
                oddfreq=max(oddfreq,it.second);
            }
        }

        return oddfreq-evenfreq;
    }
};