class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=INT_MIN;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
            maxi=max(maxi,mpp[it]);
        }

        int count=0;
        for(auto it:mpp){
            if(maxi==it.second){
                count+=maxi;
            }
        }

        return count;
    }
};