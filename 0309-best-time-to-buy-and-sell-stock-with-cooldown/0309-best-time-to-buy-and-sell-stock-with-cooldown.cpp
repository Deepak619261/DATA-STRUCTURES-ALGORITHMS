class Solution {

public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<long>front1(2,0);
        vector<long>front2(2,0);
        //  lets do tabulation


        for(int i=n-1;i>=0;i--){
            vector<long>curr(2,0);
            for(int j=0;j<2;j++){
                long profit=0;
                if(j==0){
                    profit=max((long)(-prices[i]+front1[!j]),front1[j]);
                }
                else{
                    if(i+2<n){
                        profit=max((long)(prices[i]+front2[!j]),front1[j]);
                    }
                    else{
                        //  but you can still sell the stock on this day 
                        profit=max((long)prices[i],front1[j]);  // we are taking maximum of selling on that day and previous profit if we don't 
                    }
                }
                curr[j]=profit;
            }
            front2=front1;
            front1=curr;
        }

        
        return (int)front1[0];
        
    }
};