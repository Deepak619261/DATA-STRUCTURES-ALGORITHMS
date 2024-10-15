class Solution {
    string lcs(string str1, string str2){
        int n1=str1.size();
        int n2=str2.size();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string ans="";
        int row=n1;
        int col=n2;

        while(row>0 && col>0){
            if(str1[row-1]==str2[col-1]){
                ans=str1[row-1]+ans;
                row--;
                col--;
            }
            else if(dp[row-1][col]>dp[row][col-1]){
                ans=str1[row-1]+ans;
                row--;
            }
            else{
                ans=str2[col-1]+ans;
                col--;
            }
        }

        while(row>0){
            ans=str1[row-1]+ans;
            row--;
        }

        while(col>0){
            ans=str2[col-1]+ans;
            col--;
        }

        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return lcs(str1,str2);
    }
};