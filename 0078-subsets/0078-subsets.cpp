class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // in this approach we are gonna build the power set through bit manipulation 
        int n=nums.size();

        int numofsubsets=1<<n;

        vector<vector<int>>result;

        for(int i=0;i<numofsubsets;i++){
            vector<int>store;

            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    store.push_back(nums[j]);
                }
            }
            result.push_back(store);
        }

        return result;
    }
};