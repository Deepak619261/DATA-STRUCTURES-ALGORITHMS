class Solution {
    int solve(int index1, int index2, string text1, string text2,vector<vector<int>>&dp){
        if(index1<0 || index2<0)return 0;

        if(dp[index1][index2]!=-1)return dp[index1][index2];

        if(text1[index1]==text2[index2])return 1+solve(index1-1,index2-1,text1,text2,dp);

        return dp[index1][index2]=max(solve(index1-1,index2,text1,text2,dp),solve(index1,index2-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // the very basic rule of writing the recurrence relation is firstluu 
        //  express everything in terms of index 
        //  explore every  possiblity 
        //  choose the best 
        //  optimize the memization 
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1.size()-1,text2.size()-1,text1,text2,dp);

        for(int index1=text1.size()-1;index1>=0;index1--){
            for(int index2=text2.size()-1;index2>=0;index2--){
            if(text1[index1]==text2[index2]){
                dp[index1][index2]=1+dp[index1-1][index2-1];
            } 
            else{ 
            dp[index1][index2]=max(dp[index1-1][index2],dp[index1][index2-1]);
            }

            }
        }
        return dp[0][0];
    }
};