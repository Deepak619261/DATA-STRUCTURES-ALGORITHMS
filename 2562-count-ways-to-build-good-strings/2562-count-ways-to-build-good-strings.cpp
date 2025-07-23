class Solution {
    int MOD=1e9+7;
    int solve(int index,int n , int zero , int one,int curr,vector<int>&dp){
        if(curr>=n)return 0;

        if(dp[curr]!=-1)return dp[curr];

        int pickzeros=0;
        int pickones=0;

        if(curr+zero<n)pickzeros++;

        if(curr+one<n)pickones++;


        pickzeros+=solve(index+1,n,zero,one,curr+zero,dp)%MOD;
        pickones+=solve(index+1,n,zero,one,curr+one,dp)%MOD;

        return dp[curr]=(long long)(pickzeros+pickones)%MOD;       
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        //  approach coming in my mind is to first calculate the number of possible strings till low 
        // then calculate the number of good string till high 
        //  return the diffeerence of (0-> high ) - (o-> low-1);
        vector<int>dp(low+1,-1);
        vector<int>dp2(high+2,-1);
        return (solve(0,high+1,zero,one,0,dp2)-solve(0,low,zero, one , 0,dp)+MOD)%MOD;
    }
};