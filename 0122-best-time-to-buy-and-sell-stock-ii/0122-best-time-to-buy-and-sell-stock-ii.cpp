class Solution {
    int solve(vector<int>nums,int index,int buy,vector<vector<int>>&dp){
        if(index==nums.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        //  buy==0 means we can either buy the stock or do nothing 
        int takeStock=0;
        int nottakStock=0;
        if(buy==0){
            
            takeStock=-nums[index]+solve(nums,index+1,1-buy,dp);
            nottakStock=solve(nums,index+1,buy,dp);
    
        }

        int bought=max(takeStock,nottakStock);

        int sellStock=0;
        int notsellStock=0;

        if(buy==1){

        sellStock=nums[index]+solve(nums,index+1,1-buy,dp);
        notsellStock=solve(nums,index+1,buy,dp);
        }

        int sold=max(sellStock,notsellStock);


        return dp[index][buy]= max(sold,bought);

    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();


       vector<vector<int>>dp(n+1,vector<int>(2,0));
    //    return solve(prices,0,0,dp);
       
       for(int index=n-1;index>=0;index--){
        
        for(int buy=0;buy<2;buy++){

        
        int takeStock=0;
        int nottakStock=0;
        if(buy==0){
            
            takeStock=-prices[index]+dp[index+1][1-buy];
            nottakStock=dp[index+1][buy];
    
        }

        int bought=max(takeStock,nottakStock);

        int sellStock=0;
        int notsellStock=0;

        if(buy==1){

        sellStock=prices[index]+dp[index+1][1-buy];
        notsellStock=dp[index+1][buy];
        }

        int sold=max(sellStock,notsellStock);


        dp[index][buy]= max(sold,bought);
        }
       }
        
       return dp[0][0];














        // //  whenever we see the pattern of multiple ways and something like pick and not pick
        // //  -> recursion -> try all ways -> DP
        // vector<int>prev(2,0);
        // //  doing tabulations
        

        // for(int i=n-1;i>=0;i--){
        //     vector<int>curr(2,0);
        //     for(int j=0;j<=1;j++){
        //         long profit=0;

        //         if(j==0){
        //             profit=max((long)(-prices[i]+prev[1-j]),(long)prev[j]);
        //         }
        //         else{
        //             profit=max((long)(prices[i]+prev[1-j]),(long)prev[j]);
        //         }

        //         curr[j]=profit;
        //     }
        //     prev=curr;
        // }

        // return prev[0];

        
    }
};