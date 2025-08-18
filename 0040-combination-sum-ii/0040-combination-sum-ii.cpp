class Solution {
    void solve(int index, vector<vector<int>>&ans,vector<int>temp,vector<int>&nums,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])continue;
            //  don't pick if there are same elements 
            if(target-nums[i]<0)break;
            temp.push_back(nums[i]);
            solve(i+1,ans,temp,nums,target-nums[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,ans,temp,candidates,target);
        return ans;

    }
};