class Solution {
    void solve(int index, int n,vector<vector<int>>&ds,vector<int>&store,vector<int>nums){
        if(index==n){
            ds.push_back(store);
            return;
        }

        //  pick and non pick approach 
        store.push_back(nums[index]);
        solve(index+1,n,ds,store,nums);
        store.pop_back();

        solve(index+1,n,ds,store,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ds;
        vector<int>store;
        solve(0,nums.size(),ds,store,nums);
        return ds;
    }
};