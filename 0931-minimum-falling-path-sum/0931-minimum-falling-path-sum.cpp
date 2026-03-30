class Solution {
    int solve(int i, int j , vector<vector<int>>&matrix,int n,vector<vector<int>>&dp){
        if(i==n-1)return matrix[i][j];

        if(dp[i][j]!=-1e6)return dp[i][j];

    //     going down iteration 
        int ans=matrix[i][j]+solve(i+1,j,matrix,n,dp);

        if(j-1>=0){
            ans=min(ans,matrix[i][j]+solve(i+1,j-1,matrix,n,dp));
        }
        if(j+1<n){
            ans=min(ans,matrix[i][j]+solve(i+1,j+1,matrix,n,dp));
        }

        return dp[i][j]=ans;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans=matrix[i][j]+dp[i+1][j]; 
            if(j-1>=0){
            ans=min(ans,matrix[i][j]+dp[i+1][j-1]);
        }
        if(j+1<n){
            ans=min(ans,matrix[i][j]+dp[i+1][j+1]);
        }

        dp[i][j]=ans;
            }
        }

        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res,dp[0][i]);
        }

        return res;
    }
};