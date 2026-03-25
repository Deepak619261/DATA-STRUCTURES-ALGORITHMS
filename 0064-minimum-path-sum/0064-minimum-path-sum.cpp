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


        // vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>next(n,0);
        next[n-1]=grid[m-1][n-1];
        // dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            vector<int>curri(n,0);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    curri[n-1]=grid[i][j];
                    continue;
                }
                int down=INT_MAX;
                int right=INT_MAX;
                if(i+1<m)down=next[j]+grid[i][j];
                if(j+1<n)right=curri[j+1]+grid[i][j];
                curri[j]=min(down,right);
            }
            for(auto it:curri){
                cout<<it<<" ";
            }
            cout<<endl;
            next=curri;
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return next[0];
        
        
    }
};