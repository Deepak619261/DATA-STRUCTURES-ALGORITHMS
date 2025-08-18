class Solution {
    void solve(int index, vector<int>&nums,int target,vector<vector<int>>&ans, vector<int>&temp){
        if(target<0)return;

        if(index==nums.size()){
            if(target==0){
              ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[index]);
        solve(index,nums,target-nums[index],ans,temp);
        temp.pop_back();
        solve(index+1,nums,target,ans,temp); 
       
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates,target,ans,temp);
        return ans;
    }
};