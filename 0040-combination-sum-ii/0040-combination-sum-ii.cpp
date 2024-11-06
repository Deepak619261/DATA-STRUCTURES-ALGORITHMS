class Solution {
    void solve(int index,vector<int>&nums,vector<vector<int>>&ans, int target,vector<int>&store){
    
            if(target==0){
                ans.push_back(store);
                return;
            }

            
        


        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            if(target<nums[i]) break;

            store.push_back(nums[i]);
            solve(i+1,nums,ans,target-nums[i],store);
            store.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;

        vector<int>store;
        
        sort(candidates.begin(),candidates.end());

        solve(0,candidates,ans,target,store);


        return ans;
    }
};