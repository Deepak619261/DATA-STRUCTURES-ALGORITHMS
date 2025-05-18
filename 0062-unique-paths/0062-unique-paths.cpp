class Solution {
    int solve(int row,int col , int m , int n,vector<vector<int>>&dp){
        if(row>=m || col>=n)return 0;
        if(row==m-1 && col==n-1)return 1;

        if(dp[row][col]!=-1)return dp[row][col];

        int down=solve(row+1,col,m,n,dp);
        int right=solve(row,col+1,m,n,dp);


        return  dp[row][col]=right+down;
    }
public:
    int uniquePaths(int m, int n) {
        // memoization introduced 
        // lets move to the tabulation 
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;

        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                if(row==m-1 && col==n-1)continue;
                int down=0;
                int right=0;
                if(row+1<m){
                    down=dp[row+1][col];
                }
                if(col+1<n){
                    right=dp[row][col+1];
                }

                dp[row][col]=down+right;
            }
        }


        return dp[0][0];
    }
};