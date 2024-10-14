class Solution {
    int solve(string str1, string str2 , int index1, int index2,vector<vector<int>>&dp){
        if(index1<0){
            return index2+1;
        }
        if(index2<0){
            return index1+1;
        }

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        if(str1[index1]==str2[index2]){
            return dp[index1][index2]=solve(str1,str2,index1-1,index2-1,dp);
        }
        else{
        return dp[index1][index2]=1+min(solve(str1,str2,index1,index2-1,dp),min(solve(str1,str2,index1-1,index2-1,dp),solve(str1,str2,index1-1,index2,dp)));
        }



    }
public:
    int minDistance(string word1, string word2) {
     int n1=word1.size();
     int n2=word2.size();

     vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    //   let's do tabulation 

    for(int i=0;i<=n1;i++){
        dp[i][0]=i;
    }

    for(int j=0;j<=n2;j++){
        dp[0][j]=j;
    }
    

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }


     return dp[n1][n2];  
    }
};