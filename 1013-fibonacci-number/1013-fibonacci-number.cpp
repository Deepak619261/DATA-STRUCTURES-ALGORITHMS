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
    // dp[0]=0;
    // dp[1]=1;
    int prev=1;
    int prev2=0;

    for(int index=2;index<=n;index++){
          int curri=prev+prev2;
          prev2=prev;
          prev=curri;
    }

    return prev;

        
    }
};