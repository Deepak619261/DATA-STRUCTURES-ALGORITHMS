class Solution {
    int solve(int index, int previndex, vector<int>&nums,vector<vector<int>>&dp){
        if(index==nums.size())return 0;

        if(dp[index][previndex+1]!=-1)return dp[index][previndex+1];

        int notpick=solve(index+1,previndex,nums,dp);
        int pick=0;

        if(previndex==-1 || nums[index]>nums[previndex]){
           pick=1+solve(index+1,index,nums,dp);
        }

        return dp[index][previndex+1]=max(pick,notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        //  ah , i forgot how to tabulate the recursive solution 
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);

    }
};