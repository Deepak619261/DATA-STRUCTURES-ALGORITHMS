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
        // vector<int>dp(cost.size()+2,0);

        //  lets do space optimization 
        int next1=0;
        int next2=0;

        for(int index=cost.size()-1;index>=0;index--){
            int curri=0;
            int firststep=cost[index]+next1;
            int secondstep=cost[index]+next2;

            curri=min(firststep,secondstep);
            next2=next1;
            next1=curri;
        }

        return min(next1,next2);


        // return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};