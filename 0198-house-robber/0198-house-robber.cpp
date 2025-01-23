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
        
        
        int next2=0;
        int next1=0;
        int curr=0;

        for(int i=nums.size()-1;i>=0;i--){
            int takethatcell=nums[i]+next2;
            int nottakethatcell=next1;

            curr=max(takethatcell,nottakethatcell);
            next2=next1;
            next1=curr;
        }

        return curr;
    }
};