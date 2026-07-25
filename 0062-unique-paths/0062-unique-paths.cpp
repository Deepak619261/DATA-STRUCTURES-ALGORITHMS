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
        // vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>next(n,0);
        // return solve(0,0,m,n,dp);
        // next[n-1]=1;

        for(int i=m-1;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    curr[j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i+1<m){
                  up=next[j];
                }
                if(j+1<n){
                    left=curr[j+1];
                }
                curr[j]=up+left;
            }
            next=curr;
        }

        return next[0];
    }
};