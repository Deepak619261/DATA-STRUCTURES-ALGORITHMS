class Solution {
    int solve(int i, int j , int m , int n , vector<vector<int>>&grid ,vector<vector<int>>&dp){
        if(i>=m || j>=n || grid[i][j]==1)return 0;

        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        int down=solve(i+1,j,m,n,grid,dp);
        int right=solve(i,j+1,m,n,grid,dp);

        return  dp[i][j]=down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // vector<vector<long long>>dp(m,vector<long long>(n,0));
        vector<long long>next(n,0);
        // dp[n-1]=1;

        if(obstacleGrid[m-1][n-1]==1)return 0;
        // return solve(0,0,m,n,obstacleGrid,dp);
        for(int i=m-1;i>=0;i--){
            vector<long long>curri(n,0);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    curri[j]=1;
                    continue;
                }
                long long down=0;
                long long right=0;
                if(i+1<m && obstacleGrid[i+1][j]==0 && obstacleGrid[i][j]==0){
                    down+=next[j];
                }
                if(j+1<n && obstacleGrid[i][j+1]==0 && obstacleGrid[i][j]==0){
                    right+=curri[j+1];
                }
                curri[j]=(long long)(down+right);
            }
            next=curri;
        }

        return next[0];

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // return dp[0][0];
    }
};