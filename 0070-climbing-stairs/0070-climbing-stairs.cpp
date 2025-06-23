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
        // space optimization 
       int prev=1;
       int prev2=1;

       for(int i=1;i<=n;i++){
        int curri=0;
         int onestep=prev;
         int twostep=0;
         if(i>=2){
            twostep=prev2;
         }

         curri=onestep+twostep;
         prev2=prev;
         prev=curri;
       }

       return prev;

    }
};