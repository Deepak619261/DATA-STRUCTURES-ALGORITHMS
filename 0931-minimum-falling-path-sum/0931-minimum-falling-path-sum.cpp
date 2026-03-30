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

        vector<vector<int>>dp(n,vector<int>(n,-1e6));

        for(int i=0;i<n;i++){
            ans=min(ans,solve(0,i,matrix,n,dp));
        }

        return ans;
    }
};