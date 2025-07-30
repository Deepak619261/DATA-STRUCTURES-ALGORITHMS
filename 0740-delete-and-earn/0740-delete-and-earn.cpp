class Solution {
    int solve(int index, vector<int>&nums,vector<int>&dp){
        if(index>=nums.size())return 0;

        if(dp[index]!=-1)return dp[index];


        int currsum=nums[index];
        int i=index+1;
        int currval=nums[index];

        while(i<nums.size() && nums[i]==nums[index])
        {
             currsum+=nums[i];
             i++;
        }

        while(i<nums.size() && nums[i]==currval+1){
            i++;
        }
        currsum+=solve(i,nums,dp);
        int otherchoice=solve(index+1,nums,dp);

        return dp[index]=max(currsum,otherchoice);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // see after sorting the array , we are sure that we won't be missing the arr[i]-1 case why because if we are starting from the middle of the array we are very sure that we have already skipped the arr[i]-1 element 
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);

    }
};