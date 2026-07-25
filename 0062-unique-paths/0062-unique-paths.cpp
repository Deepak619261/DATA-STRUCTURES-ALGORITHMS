class Solution {
    int solve(int i,int j,int m , int n,vector<vector<int>>&dp){
        if(i>=m || j>=n)return 0;


        if(dp[i][j]!=-1)return dp[i][j];

        if(i==m-1 && j==n-1)return 1;

        // visited[i][j]=true;
        int down=solve(i+1,j,m,n,dp);
        int right=solve(i,j+1,m,n,dp);
        // visited[i][j]=false;



        return dp[i][j]=down+right;
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
        // dp[m-1][n-1]=1;

        // for(int i=m-1;i>=0;i--){
        //     for(int j=n-1;j>=0;j--){
        //         int up=0;
        //         int left=0;
        //         if(i+1<m){
        //           up=dp[i+1][j];
        //         }
        //         if(j+1<n){
        //             left=dp[i][j+1];
        //         }
        //     }
        // }
    }
};