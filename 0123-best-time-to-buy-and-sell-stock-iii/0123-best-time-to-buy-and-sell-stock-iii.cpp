class Solution {
    // long solve(vector<int>nums,int index,int cnt, int buy,vector<vector<vector<long>>>&dp){
    //     if(cnt==2){
    //         return 0;
    //     }

    //     if(index==nums.size()){
    //         return 0;
    //     }

    //     if(dp[index][buy][cnt]!=-1){
    //         return dp[index][buy][cnt];
    //     }

    //     //  there will be also two cases , sold and buy 
    //     long profit=0;

    //     if(buy){
    //         //  two choices here -> buy or not buy
    //         profit=max(-nums[index]+solve(nums,index+1,cnt,!buy,dp),solve(nums,index+1,cnt,buy,dp));
    //     }
    //     else{
    //         profit=max(nums[index]+solve(nums,index+1,cnt+1,!buy,dp),solve(nums,index+1,cnt,buy,dp));
    //     }

    //     return dp[index][buy][cnt]=profit;

    // }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

       
        //  let's do some tabulation & space optimization 

        vector<vector<long>>prev(2,vector<long>(3,0));

        //  base case 
        for(int i=n-1;i>=0;i--){
            vector<vector<long>>curr(2,vector<long>(3,0));
            for(int j=0;j<2;j++){
                for(int k=0;k<=2;k++){
                    long profit=0;
                    if(j==1){
                         profit=max(-prices[i]+prev[!j][k],prev[j][k]);
                    }
                    else{
                        if(k+1<=2){
                        profit=max(prices[i]+prev[!j][k+1],prev[j][k]);
                        }
                        else{
                            profit=prev[j][k];
                        }
                    }

                    curr[j][k]=profit;
                }
            }
            prev=curr;

        }


//  because we considered buy as 1 for buying the stock 
        
        return prev[1][0];
    }
};