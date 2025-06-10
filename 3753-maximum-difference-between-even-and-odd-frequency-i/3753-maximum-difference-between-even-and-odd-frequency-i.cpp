class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        int a1=INT_MIN;
        int a2=INT_MAX;

        for(auto it:mpp){
           if(it.second%2==0){
            a2=min(a2,it.second);
           }
           else{
            a1=max(a1,it.second);
           }
        }
        if(a2==INT_MAX)return a1;
        if(a1==INT_MIN)return 0;
        return a1-a2;
    }
};