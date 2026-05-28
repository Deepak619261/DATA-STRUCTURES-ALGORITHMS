class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int maxi=prices.back();
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>maxi){
               maxi=prices[i];
            }
            else{
                ans=max(ans,maxi-prices[i]);
            }
        }

        return ans;
    }
};