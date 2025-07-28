class Solution {
    int solve(int index, vector<int>&nums,int n,vector<int>&dp){
        if(index>=n)return 0;


        if(dp[index]!=-1)return dp[index];

        // we got two option either pick the current house and move index+2 
        // or don't pick and just move forward 
        int pick=nums[index]+solve(index+2,nums,n,dp);

        int dontpick=solve(index+1,nums,n,dp);

        return dp[index]=max(pick,dontpick);
    }
public:
    int rob(vector<int>& nums) {
        // there will be the flow same as the house robber i but we will check the two config , one is that we will start from 0 and second we will start from 1 
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n+1,0);
        vector<int>dp2(n+2,0);

        // first loop with dp 1 
        for(int i=n-2;i>=0;i--){
            int pick=nums[i]+dp1[i+2];
            int dontpick=dp1[i+1];
            dp1[i]=max(pick,dontpick);
        }

        for(int i=n-1;i>=1;i--){
            int pick=nums[i]+dp2[i+2];
            int dontpick=dp2[i+1];
            dp2[i]=max(pick,dontpick);
        }


        return max(dp1[0],dp2[1]);

       
    }
};