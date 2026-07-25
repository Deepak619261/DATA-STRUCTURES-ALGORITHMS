class Solution {
    int solve(int i,int j,vector<vector<bool>>&visited,int m , int n,vector<vector<int>>&dp){
        if(i>=m || j>=n || visited[i][j])return 0;


        if(dp[i][j]!=-1)return dp[i][j];

        if(i==m-1 && j==n-1)return 1;

        visited[i][j]=true;
        int down=solve(i+1,j,visited,m,n,dp);
        int right=solve(i,j+1,visited,m,n,dp);
        visited[i][j]=false;



        return dp[i][j]=down+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,visited,m,n,dp);
    }
};