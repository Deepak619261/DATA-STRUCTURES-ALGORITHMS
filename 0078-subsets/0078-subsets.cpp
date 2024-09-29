class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        
        int numofsubsets=(1<<n);

        vector<vector<int>>ans;

        for(int i=0;i<numofsubsets;i++){
            vector<int>store;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    store.push_back(nums[j]);
                }
            }
            ans.push_back(store);
        }

        return ans;
    }
};