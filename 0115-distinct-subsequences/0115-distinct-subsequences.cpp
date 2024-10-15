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
        vector<vector<unsigned long long>>dp(n1+1,vector<unsigned long long >(n2+1,0));
        //  let's tabulate this 

        for(int i=0;i<=n1;i++){
            dp[i][0]=1;
        }
        

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }

            }
        }


        return dp[n1][n2];
    }
};