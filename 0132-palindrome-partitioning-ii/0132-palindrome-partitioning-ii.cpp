class Solution {

public:
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        //  let's do tabulation
        

        vector<vector<bool>>isPal(n,vector<bool>(n,false));

        // single character is always palindromic

        for(int i=0;i<n;i++){
            isPal[i][i]=true;
        }

        for(int len=2;len<=s.size();len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len==2 || isPal[i+1][j-1]){
                        isPal[i][j]=true;
                    }
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            int minCuts=INT_MAX;

        for(int j=i;j<s.size();j++){
            if(isPal[i][j]){
                int cuts=1+dp[j+1];
                minCuts=min(minCuts,cuts);
            }
        }

        dp[i]=minCuts;



        }












        return dp[0]-1;
    }
};