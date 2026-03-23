class Solution {
    int solve(int i , int j,vector<vector<int>>&grid,int m ,int n,vector<vector<int>>&dp){
        if(i>=m || j>=n)return INT_MAX;
        if(i==m-1 && j==n-1)return grid[i][j];
        
        if(dp[i][j]!=-1)return dp[i][j];


        int down=solve(i+1,j,grid,m,n,dp);
        int right=solve(i,j+1,grid,m,n,dp);

        if(down!=INT_MAX)down+=grid[i][j];
        if(right!=INT_MAX)right+=grid[i][j];



        return dp[i][j]=min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();


        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(0,0,grid,m,n,dp);
        
        
    }
};