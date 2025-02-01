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
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(16,0)));
        // lets do tabulation 
        
        for(int i=0;i<16;i++){
            if((grid[m-1][n-1]^i)==k){
                dp[m-1][n-1][i]=1;

            }
        }


        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                for(int xorval=0;xorval<16;xorval++){
                    if(row==m-1 && col==n-1)continue;
                    int down=0;
                    int right=0;
                    if(row+1<m){
                       down=dp[row+1][col][xorval^grid[row][col]];
                    }
                    if(col+1<n){
                        right=dp[row][col+1][xorval^grid[row][col]];
                    }

                    dp[row][col][xorval]=(down+right)%MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};