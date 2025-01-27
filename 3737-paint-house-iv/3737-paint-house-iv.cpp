class Solution {
    long long solve(int index, vector<vector<int>>&cost , int prev1, int prev2,int n,vector<vector<vector<long long>>>&dp){
        if(index>=(n/2)){
            return 0;
        }

        if(dp[index][prev1][prev2]!=-1)return dp[index][prev1][prev2];
        long long res=LLONG_MAX;

        // try all the possible combinatioin to fill mirrored indices 
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
               // condition to paint a house 
               

               if(i!=j && i!=prev1 && j!=prev2){
                  res=min(res,cost[index][i-1]+cost[n-index-1][j-1]+solve(index+1,cost,i,j,n,dp));
               }
            }
        }
        return dp[index][prev1][prev2]=res;
    }
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>>dp(n,vector<vector<long long >>(5,vector<long long>(5,-1)));
        return solve(0,cost,4,4,n,dp);
    }
};