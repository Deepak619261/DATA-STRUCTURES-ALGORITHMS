class Solution {
    int MOD=1e9+7;
    int solve(int row , int col, vector<vector<int>>&grid , long long xorval,int m , int n,int k,vector<vector<vector<int>>>&dp){
        // base conditon 
        if(row==m-1 && col==n-1){
            if((xorval^grid[row][col])==k)return 1;
            return 0;
        }

        if(row<0 || col<0 || row>=m || col>=n)return 0;


        // we have two options only , the very first option is to go in down direction and the second option is to go in right direction 

        if(dp[row][col][xorval]!=-1)return dp[row][col][xorval];
        int downxor=solve(row+1,col,grid,xorval^grid[row][col],m,n,k,dp);
        int rightxor=solve(row,col+1,grid,xorval^grid[row][col],m,n,k,dp);


        return dp[row][col][xorval]=(downxor+rightxor)%MOD;
    }
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(16,-1)));
        return solve(0,0,grid,0,m,n,k,dp);
    }
};