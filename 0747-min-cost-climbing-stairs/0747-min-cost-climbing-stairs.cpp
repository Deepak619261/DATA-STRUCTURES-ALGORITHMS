class Solution {
    int solve(int index, vector<int>&cost,vector<int>&dp){
        if(index>=cost.size())return 0;

        if(dp[index]!=-1)return dp[index];

        // we have two choices either to reach first flor and the two steps
        int firststep=cost[index]+solve(index+1,cost,dp);
        int secondstep=cost[index]+solve(index+2,cost,dp);

        return dp[index]=min(firststep,secondstep);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // start with either 0 or 1 
        vector<int>dp(cost.size(),-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};