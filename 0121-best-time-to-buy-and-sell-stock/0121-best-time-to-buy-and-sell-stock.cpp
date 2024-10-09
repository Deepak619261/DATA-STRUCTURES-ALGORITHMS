class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        
        int bP=prices[0];
    
        for(int i=0;i<prices.size();i++){
            if(bP>prices[i]){
                bP=prices[i];
            }
            
            ans=max(ans,prices[i]-bP);
        }

        return ans;
    }
};