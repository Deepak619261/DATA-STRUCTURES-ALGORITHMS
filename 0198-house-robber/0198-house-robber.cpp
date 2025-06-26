class Solution {
    int solve(int index, vector<int>&nums,vector<int>&dp){
        if(index>=nums.size())return 0;

        if(dp[index]!=-1)return dp[index];

        int pickhouse=nums[index]+solve(index+2,nums,dp);
        int dontpickhouse=solve(index+1,nums,dp);

        return dp[index]=max(pickhouse,dontpickhouse);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];

        vector<int>dp(nums.size(),-1);
        
        return solve(0,nums,dp);

       
    }
};