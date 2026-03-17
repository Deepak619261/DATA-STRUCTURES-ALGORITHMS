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
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)continue;
                int down=0;
                int right=0;
                if(i+1<=m-1)down+=dp[i+1][j];
                if(j+1<=n-1)right+=dp[i][j+1];

                dp[i][j]=down+right;
            }
        }

        for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        cout << dp[i][j] << " ";
    }
    cout << endl;
}
        return dp[0][0];
        
    }
};