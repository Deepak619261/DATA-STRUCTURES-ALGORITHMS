class Solution {
    long solve(vector<int>nums,int index,int buy,vector<vector<long>>&dp){
        if(index>=nums.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        long profit=-1e9;
        if(buy==0){
            profit=max((long)(-nums[index]+solve(nums,index+1,!buy,dp)),solve(nums,index+1,buy,dp));
        }
        else{
            profit=max((long)(nums[index]+solve(nums,index+2,!buy,dp)),solve(nums,index+1,buy,dp));
        }

        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<vector<long>>dp(n+1,vector<long>(2,0));
        //  lets do tabulation


        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long profit=0;
                if(j==0){
                    profit=max((long)(-prices[i]+dp[i+1][!j]),dp[i+1][j]);
                }
                else{
                    if(i+2<n){
                        profit=max((long)(prices[i]+dp[i+2][!j]),dp[i+1][j]);
                    }
                    else{
                        //  but you can still sell the stock on this day 
                        profit=max((long)prices[i],dp[i+1][j]);  // we are taking maximum of selling on that day and previous profit if we don't 
                    }
                }
                dp[i][j]=profit;
            }
        }

        
        return (int)dp[0][0];
        
    }
};