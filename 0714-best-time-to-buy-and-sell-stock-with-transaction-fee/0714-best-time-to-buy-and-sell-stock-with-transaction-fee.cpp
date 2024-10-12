class Solution {
    long solve(vector<int>nums, int fee, int index,int buy,vector<vector<long>>&dp){
        if(index==nums.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }


        long profit=0;

        if(buy==0){
            profit=max((long)(-nums[index]+solve(nums,fee,index+1,!buy,dp)),solve(nums,fee,index+1,buy,dp));
        }
        else{
            profit=max((long)(nums[index]-fee+solve(nums,fee,index+1,!buy,dp)),solve(nums,fee,index+1,buy,dp));
        }

        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<long>>dp(n+1,vector<long>(2,0)); 

        // let's do tabulation 

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long profit=0;
                if(j==0){
                    
                    profit=max(-prices[i]+dp[i+1][!j],dp[i+1][j]);

                }
                else{

                    profit=max(prices[i]-fee+dp[i+1][!j],dp[i+1][j]);

                }
                dp[i][j]=profit;
            }

        }



         
        return dp[0][0];
        
    }
};