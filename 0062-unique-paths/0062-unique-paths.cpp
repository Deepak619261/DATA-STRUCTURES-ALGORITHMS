class Solution {
    int solve(int row, int col, int m, int n,vector<vector<int>>&dp){
        if(row==m-1 && col==n-1){
            return 1;
        }

        if(row<0 || col<0 || row>=m || col>=n)return 0;
         
        if(dp[row][col]!=-1)return dp[row][col];
        int down=solve(row+1,col,m,n,dp);
        int right=solve(row,col+1,m,n,dp);

        return dp[row][col]=down+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int row=m-1;row>=0;row--){
            // vector<int>curr;
            for(int col=n-1;col>=0;col--){
                if(row==m-1 && col==n-1){
                    curr[col]=1;
                }
                else{
                int down=next[col];
                int right=curr[col+1];
                curr[col]=down+right;
                }
            }
            next=curr;
        }

        return curr[0];
    }
};