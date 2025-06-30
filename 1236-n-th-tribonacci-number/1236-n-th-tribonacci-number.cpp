class Solution {
    int solve(int n, vector<int>&dp){
        
        if(dp[n]!=-1)return dp[n];

        return dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
    }
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;
        

        vector<int>dp(n+1,0);
        int prev=1;
        int prev2=1;
        int prev3=0;
        
        for(int i=3;i<=n;i++){
            int curri=prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            prev=curri;
        }

        return prev;
    }
};