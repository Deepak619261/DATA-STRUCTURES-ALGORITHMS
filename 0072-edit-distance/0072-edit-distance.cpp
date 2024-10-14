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

     vector<vector<int>>dp(n1,vector<int>(n2,-1));

     return solve(word1,word2,n1-1,n2-1,dp);   
    }
};