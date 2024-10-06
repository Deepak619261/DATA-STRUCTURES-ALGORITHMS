class Solution {
    int solve(vector<int>coins, int amount ,int index,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            return 1e9;
        }


        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }

        //  there may be two possiblities 
        //  first we can take one coin second we can't
        //  but when we are taking one coin then there is mentioned that supply of the coin is unlimited so we won't get to the next coin untill value of the amount is below coin  

        //  taking the coin 
        int taken=1e9;
        if(coins[index]<=amount){

            //  crux of the logic lies here in this line 
            taken=1+solve(coins,amount-coins[index],index,dp);
        }

        int nottaken=solve(coins,amount,index-1,dp);

        return dp[index][amount]=min(taken,nottaken);
    }
public:
    int coinChange(vector<int>& coins, int amount) {

     if(amount==0){
        return 0;
     }
     int n=coins.size();
    //   tabulation 
    vector<int>prev(amount+1,0);

    //  base condition 
    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            prev[i]=i/coins[0];
        }
        else{
            prev[i]=1e9;
        }
    }

    for(int ind=1;ind<n;ind++){
        vector<int>curr(amount+1,0);
        for(int j=0;j<=amount;j++){
            int taken=1e9;
            if(coins[ind]<=j){
                taken=1+curr[j-coins[ind]];
            }
            int nottaken=prev[j];

            curr[j]=min(taken,nottaken);
        }
        prev=curr;
    }

    int ans=prev[amount];
    
    if(ans>=1e9) return -1;

    return ans;

    }
};