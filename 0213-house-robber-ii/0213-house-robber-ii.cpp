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
        // vector<int>dp1(n+1,0);
        vector<int>dp2(n+2,0);
        int next2=0;
        int next1=0;
        // first loop with dp 1 
        for(int i=n-2;i>=0;i--){
            int pick=nums[i]+next2;
            int dontpick=next1;
            int curri=max(pick,dontpick);

            next2=next1;
            next1=curri;
        }


        int nexi2=0;
        int nexi1=0;

        for(int i=n-1;i>=1;i--){
            int pick=nums[i]+nexi2;
            int dontpick=nexi1;
            int curri=max(pick,dontpick);
            nexi2=nexi1;
            nexi1=curri;
        }


        return max(next1,nexi1);

       
    }
};