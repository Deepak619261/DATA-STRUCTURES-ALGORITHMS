class Solution {
    int solve(int n , vector<int>&dp){
        // memoization 
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }

    
public:
    int climbStairs(int n) {

        //  space optimization with tabulation 
      if(n<=1)return n;  
      vector<int>dp(n+1,-1);
      int prev2=1;
      int prev=1;
      for(int i=2;i<=n;i++){
        int curri=prev+prev2;
        prev2=prev;
        prev=curri;
      }

      return prev;
        
    }
};