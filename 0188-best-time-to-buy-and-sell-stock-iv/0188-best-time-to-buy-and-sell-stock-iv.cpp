class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n=prices.size();

       
        //  let's do some tabulation & space optimization 
        int K=k;

        vector<vector<long>>prev(2,vector<long>(K+1,0));

        //  base case 
        for(int i=n-1;i>=0;i--){
            vector<vector<long>>curr(2,vector<long>(K+1,0));
            for(int j=0;j<2;j++){
                for(int k=0;k<=K;k++){
                    long profit=0;
                    if(j==1){
                         profit=max(-prices[i]+prev[!j][k],prev[j][k]);
                    }
                    else{
                        if(k+1<=K){
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