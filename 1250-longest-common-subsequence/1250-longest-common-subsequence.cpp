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
         int m = text1.size(), n = text2.size();
    vector<int> prev(n, 0), curr(n, 0);
    
    for (int index1 = m - 1; index1 >= 0; index1--) {
        for (int index2 = n - 1; index2 >= 0; index2--) {
            if (text1[index1] == text2[index2]) {
                curr[index2] = 1 + (index1 + 1 < m && index2 + 1 < n ? prev[index2 + 1] : 0);
            } else {
                curr[index2] = max((index1 + 1 < m ? prev[index2] : 0), (index2 + 1 < n ? curr[index2 + 1] : 0));
            }
        }
        prev = curr; // Move current row to previous row
    }
    return prev[0];
    }
};