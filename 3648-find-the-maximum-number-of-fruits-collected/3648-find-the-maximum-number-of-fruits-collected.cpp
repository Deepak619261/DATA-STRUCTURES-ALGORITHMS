class Solution {
    int uprightchild(int i , int j , int n , vector<vector<int>>&fruits,vector<vector<int>>&dp){
         if(i==n-1 && j==n-1)return 0;


        //  invalid condition 
        if(i>=n || j>=n || i<0 || j<0 || i==j)return INT_MIN;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;
        ans=fruits[i][j]+max(uprightchild(i+1,j-1,n,fruits,dp),max(uprightchild(i+1,j,n,fruits,dp),uprightchild(i+1,j+1,n,fruits,dp)));

        return dp[i][j]=ans;
    }

    int bottomleftchild(int i, int j , int n , vector<vector<int>>&fruits,vector<vector<int>>&dp){
        if(i==n-1 && j==n-1)return 0;

        if(i>=n || i<0 || j>=n || j<0 || i==j)return INT_MIN;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;
        ans=fruits[i][j]+max(bottomleftchild(i-1,j+1,n,fruits,dp),max(bottomleftchild(i,j+1,n,fruits,dp),bottomleftchild(i+1,j+1,n,fruits,dp)));

        return dp[i][j]=ans;
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int diagSum=0;
        for(int i=0;i<fruits.size();i++){
            diagSum+=fruits[i][i];
        }
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));


        //  actually problem get break down into two child only because we can't take any other path for the first child as if we took any other path we will have to take the steps more than n-1 so we have to just take the recursive cases for both the children remaining 
       return diagSum+bottomleftchild(n-1,0,n,fruits,dp1)+uprightchild(0,n-1,n,fruits,dp2);

    }
};