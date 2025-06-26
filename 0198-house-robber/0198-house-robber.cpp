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

        vector<int>dp(nums.size()+1,0);

        for(int i=nums.size()-1;i>=0;i--){
            int pickhouse=nums[i];
            int dontpickhouse=0;
            if(i+2<nums.size()){
               pickhouse+=dp[i+2];
            }
            if(i+1<nums.size()){
               dontpickhouse=dp[i+1];
            }

            dp[i]=max(dontpickhouse,pickhouse);
        }
        
        return dp[0];

       
    }
};