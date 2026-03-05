class Solution {
    int solve(int index, vector<int>&nums,vector<int>&dp){
        if(index>=nums.size())return 0;


        if(dp[index]!=-1)return dp[index];

        // we should not use the INT_MIN as in any case it can just pick the negative value in max value picking so that case 
        // INT_MIN + some negative value --> will cause the overflow 

        //  it can have two choice , it can pick the current one and move index+2 ,
        // or it just don't pick the one and just move one ahead index+1 
        int pick=nums[index]+solve(index+2,nums,dp);
        int dontpick=solve(index+1,nums,dp);

        return dp[index]=max(pick,dontpick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);

        for(int index=nums.size()-1;index>=0;index--){
            int pick=nums[index];
            if(index+2<=nums.size()){
                pick+=dp[index+2];
            }
            int dontpick=dp[index+1];
            dp[index]=max(pick,dontpick);
        }

        return dp[0];
    }
};