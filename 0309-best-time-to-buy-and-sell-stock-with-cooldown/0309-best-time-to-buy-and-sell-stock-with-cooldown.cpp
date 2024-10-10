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
        vector<vector<long>>dp(n+1,vector<long>(2,-1));
        return (int)solve(prices,0,0,dp);
        
    }
};