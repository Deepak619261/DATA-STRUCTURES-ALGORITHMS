class Solution {

public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<double>>dp(n,vector<double >(amount+1,0));

        //  tabulation 
        for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            dp[0][i]=1;
        }
        }
        
        
    for(int ind=1;ind<n;ind++){
        for(int j=0;j<=amount;j++){
            double taken=0;
            if(coins[ind]<=j){
                taken=dp[ind][j-coins[ind]];
            }
            double nottaken=dp[ind-1][j];
            dp[ind][j]=(taken+nottaken);
        }
    }


    return dp[n-1][amount];
    // return 0;


    }
};