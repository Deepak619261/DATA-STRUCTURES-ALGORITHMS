class Solution {
    int solve(int index, vector<int>&nums,vector<int>&dp){
        if(index>=nums.size())return 0;

        if(dp[index]!=-1)return dp[index];

        int takethatcell=nums[index]+solve(index+2,nums,dp);

        int nottakethatcell=solve(index+1,nums,dp);

        return dp[index]=max(takethatcell,nottakethatcell);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};