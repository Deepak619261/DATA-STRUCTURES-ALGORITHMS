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
        
        vector<int>dp(n+1,0);
       

        //  this was the top down approach ,why because we going to base case from the bigger problems 
        // now we will see the bottom up appraoch 
       dp[0]=1;

       for(int i=1;i<=n;i++){
         int onestep=dp[i-1];
         int twostep=0;
         if(i>=2){
            twostep=dp[i-2];
         }

         dp[i]=onestep+twostep;
       }

       return dp[n];

    }
};