class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //  striaght forward appraoch that comes to mind is just use the map 
        unordered_map<int,int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }

        vector<int>ans;

        int lim=nums.size()/3;

        for(auto it:mpp){
            if(it.second>lim)ans.push_back(it.first);
        }

        return ans;
    }
};