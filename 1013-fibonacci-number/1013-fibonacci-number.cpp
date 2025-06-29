class Solution {
    int solve(int n,vector<int>&dp) {
        if(n<=1)return n;

        if(dp[n]!=-1)return dp[n];

        return dp[n]=fib(n-1)+fib(n-2);
    }
public:
    int fib(int n) {
    if(n<=1)return n;
    vector<int>dp(n+1,-1);
    //    return solve(n,dp);
    dp[0]=0;
    dp[1]=1;

       for(int index=2;index<=n;index++){
          dp[index]=dp[index-1]+dp[index-2];
       }

    return dp[n];

        
    }
};