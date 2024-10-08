class Solution {
        int solve(vector<int>coins, int amount ,int index,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[0]==0){
                return 1;
            }
            return 0;
        }


        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }

        //  there may be two possiblities 
        //  first we can take one coin second we can't
        //  but when we are taking one coin then there is mentioned that supply of the coin is unlimited so we won't get to the next coin untill value of the amount is below coin  

        //  taking the coin 
        int taken=0;
        if(coins[index]<=amount){

            //  crux of the logic lies here in this line 
            taken=solve(coins,amount-coins[index],index,dp);
        }

        int nottaken=solve(coins,amount,index-1,dp);

        return dp[index][amount]=taken+nottaken;
    }
public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(coins,amount,n-1,dp);

    }
};