class Solution {
    void solve(int index, int n ,vector<int>nums,int target, vector<vector<int>>&result, vector<int>&store){
        if(index==n){
            if(target==0){
                result.push_back(store);
            }
            return;
        }

        if(nums[index]<=target){
            // pick 
            store.push_back(nums[index]);
            solve(index,n,nums,target-nums[index],result,store);
            store.pop_back();
        }

        // non pick
        solve(index+1,n,nums,target,result,store);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>store;
        solve(0,candidates.size(),candidates,target,ans,store);

        return ans;
    }
};