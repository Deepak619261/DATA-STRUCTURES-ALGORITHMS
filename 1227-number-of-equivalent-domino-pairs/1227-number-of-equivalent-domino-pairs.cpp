class Solution {
   
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // sort(dominoes.begin(),dominoes.end());
        map<pair<int,int>,int>mpp;
        for(auto it:dominoes){
            if(it[0]>it[1]){
                swap(it[0],it[1]);
            }
            mpp[{it[0],it[1]}]++;
        }

        int count=0;

        for(auto it:mpp){
            if(it.second>1){
                count+=((it.second)*(it.second-1))/2;
            }
        }

        return count;
    }
};