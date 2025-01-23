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
        vector<int>dp(nums.size()+2,0);
        

        for(int i=nums.size()-1;i>=0;i--){
            int takethatcell=nums[i]+dp[i+2];
            int nottakethatcell=dp[i+1];

            dp[i]=max(takethatcell,nottakethatcell);
        }

        return dp[0];
    }
};