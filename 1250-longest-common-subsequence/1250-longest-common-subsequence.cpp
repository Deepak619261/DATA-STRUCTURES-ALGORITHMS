class Solution {
    int solve(string str1 , string str2, int index1, int index2,vector<vector<int>>&dp){
        if(index1<0 || index2<0){
            return 0;
        }

        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }

        if(str1[index1]==str2[index2]){
            return 1+solve(str1,str2,index1-1,index2-1,dp);
        }

        return  dp[index1][index2]=max(solve(str1,str2,index1-1,index2,dp),solve(str1,str2,index1,index2-1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        //  lets do tabulation 
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){   // we have done the coordinate shifting 
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n1][n2];
    }
};