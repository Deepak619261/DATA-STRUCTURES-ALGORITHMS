class Solution {
    int solve(int i , int j , vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==triangle.size()-1)return triangle[i][j];


        if(dp[i][j]!=-1)return dp[i][j];


        int current=triangle[i][j];
        int first=solve(i+1,j,triangle,dp);
        int second=solve(i+1,j+1,triangle,dp);

        
        

        return dp[i][j]=current+min(first,second);
        

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<int>front(n,0);

        for(int j=0;j<triangle[m-1].size();j++){
            front[j]=triangle[m-1][j];// base case herew 
        }

        for(int i=m-2;i>=0;i--){
            // we 
            vector<int>curri(n,0);
            for(int j=0;j<=i;j++){
                int curr=triangle[i][j];
                int first=front[j];
                int second=front[j+1];
                curri[j]=curr+min(first,second);
            }
            front=curri;
            
        }

        return front[0];
        
    }
};