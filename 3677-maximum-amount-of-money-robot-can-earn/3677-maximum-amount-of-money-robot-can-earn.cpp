class Solution {
    int solve(int row , int col , vector<vector<int>>&coins,int ncount,int m,int n,vector<vector<vector<int>>>&dp){
        if(row==m-1 && col==n-1){
           if(coins[row][col] < 0) {
                if(ncount<2){
                    return 0;
                }
                else{
                    return coins[row][col];
                }
            }
            return coins[row][col]; 
        }

        if(row>=m || col>=n || row<0 || col<0)return INT_MIN;


        if(dp[row][col][ncount]!=-1)return dp[row][col][ncount];

        // there may be two cases either a grid can be positive or negative 
        int sum=INT_MIN;

        int nextbest=max(solve(row+1,col,coins,ncount,m,n,dp),solve(row,col+1,coins,ncount,m,n,dp));

        // int sum=0;
        if(coins[row][col]>=0){
            sum=coins[row][col]+nextbest;
        }
        

        
        
        if(coins[row][col]<0){
            // here comes two choices either we can pick or neutralize the 
            int withN=INT_MIN;
            if(ncount<2){
              withN=0+max(solve(row+1,col,coins,ncount+1,m,n,dp),solve(row,col+1,coins,ncount+1,m,n,dp));
            }
          
            int withoutN=coins[row][col]+nextbest;
            sum=max(withN,withoutN);
        }


        return dp[row][col][ncount]=sum;

    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,-1e9)));

        // lets go with tabulation 
        // return solve(0,0,coins,0,m,n,dp);
       dp[m-1][n-1][2]=coins[m-1][n-1];
       if(coins[m-1][n-1]>=0){
         dp[m-1][n-1][0]=dp[m-1][n-1][1]=dp[m-1][n-1][2]=coins[m-1][n-1];
       }
       else{
        dp[m-1][n-1][0]=dp[m-1][n-1][1]=0;
        dp[m-1][n-1][2]=coins[m-1][n-1];
       }

       
       for(int row=m-1;row>=0;row--){
          for(int col=n-1;col>=0;col--){
             if(row==m-1 && col==n-1)continue;
             for(int ncount=0;ncount<3;ncount++){



            //   ********************
            //  if(row+1>=m || col+1>=n || row<0 || col<0)continue; 
             int sum=-1e9;
             int nextbest=-1e9;
             
             

               if(row+1<m){
                  nextbest=max(nextbest,dp[row+1][col][ncount]);
               }
               if(col+1<n){
                nextbest=max(nextbest,dp[row][col+1][ncount]);
               }
             

    
             if(coins[row][col]>=0){
              sum=coins[row][col]+nextbest;
              }
        

        
        
            if(coins[row][col]<0){
            // here comes two choices either we can pick or neutralize the 
            int withN=-1e9;
            if(ncount<2){
              if(row+1<m){
                withN=max(withN,dp[row+1][col][ncount+1]);
              }
              if(col+1<n){
                withN=max(withN,dp[row][col+1][ncount+1]);
              }
            }
          
            int withoutN=coins[row][col]+nextbest;
            sum=max(withN,withoutN);
        }


        dp[row][col][ncount]=sum;



















             }
          }
       }



       return dp[0][0][0];
    }
};