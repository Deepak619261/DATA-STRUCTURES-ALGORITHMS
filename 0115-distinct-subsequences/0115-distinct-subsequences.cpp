class Solution {
    int distinctsubseq(string s, string t, int i, int j,vector<vector<int>>&dp){
        
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return dp[i][j]=distinctsubseq(s,t,i-1,j-1,dp)+distinctsubseq(s,t,i-1,j,dp);
        }
        else{
            return dp[i][j]=distinctsubseq(s,t,i-1,j,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));

        return distinctsubseq(s,t,n1-1,n2-1,dp);
    }
};