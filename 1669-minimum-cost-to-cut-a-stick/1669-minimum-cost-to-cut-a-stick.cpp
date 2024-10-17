class Solution {
    int solve(vector<int>cuts,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            // not cosidering the case of i==j because there may be still the lenght and cut is possible 
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];

        int mini=1e9;

        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp);
            mini=min(cost,mini);
        }

        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int N=cuts.size();


        // adding extra element to calculate the length of the rod before cuttting 
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);


        vector<vector<int>>dp(N+2,vector<int>(N+2,0));

        //  let's do tabulation 

        for(int i=N;i>=1;i--){
            for(int j=i;j<=N;j++){
                //  recursive logic daal do 


        int mini=1e9;

        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
            mini=min(cost,mini);
        }

        dp[i][j]=mini;

            }
        }
    

        

        return dp[1][N];
        
    }
};