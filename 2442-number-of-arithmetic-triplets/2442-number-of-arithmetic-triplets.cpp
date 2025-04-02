class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int>mpp;
        unordered_set<int>st;
        for(auto it:nums){
            mpp[it]++;
        }
        
        int count=0;

        for(int it:nums){
           if(mpp[it+diff]!=0 && mpp[it+2*diff] && st.count(it)==0){
              count++;
              mpp[it]--;
              if(mpp[it]==0){
                mpp.erase(it);
              }
           }
        }

        return count;
    }
};