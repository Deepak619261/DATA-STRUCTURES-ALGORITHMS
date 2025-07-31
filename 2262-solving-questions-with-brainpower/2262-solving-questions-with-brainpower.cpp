class Solution {
    long long solve(int index, vector<vector<int>>&nums,vector<long long >&dp){
        if(index>=nums.size())return 0;


        if(dp[index]!=-1)return dp[index];


        //  we got two choice on each pair , either we pick and move the index +=nums[index][1] or we don't pick and just get to the next question only 
        long long  pick=nums[index][0]+solve(index+nums[index][1]+1,nums,dp);
        long long dontpick=solve(index+1,nums,dp);

        return dp[index]=max(pick,dontpick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        return solve(0,questions,dp);
    }
};