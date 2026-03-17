class Solution {
    int solve(int i , int j , int m , int n,vector<vector<int>>&dp){
        if(i>=m || j>=n)return 0;

        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        int down=solve(i+1,j,m,n,dp);
        int right=solve(i,j+1,m,n,dp);
        return dp[i][j]=down+right;

    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>below(n,0);
        below[n-1]=1;

        for(int i=m-1;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    curr[j]=1;
                    continue;
                }
                int down=0;
                int right=0;
                if(i+1<=m-1)down+=below[j];
                if(j+1<=n-1)right+=curr[j+1];

                curr[j]=down+right;
            }
            below=curr;
        }

//    ,
        return below[0];
        
    }
};