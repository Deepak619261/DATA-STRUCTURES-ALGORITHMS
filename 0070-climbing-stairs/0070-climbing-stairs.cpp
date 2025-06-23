class Solution {
    int solve(int n,vector<int>&dp){
        if(n<=0)return 1;

        if(dp[n]!=-1)return dp[n];

        int onestep=solve(n-1,dp);
        int twostep=0;
        if(n>=2)twostep=solve(n-2,dp);

        return dp[n]=onestep+twostep;
    }
    
public:
    int climbStairs(int n) {
        
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};