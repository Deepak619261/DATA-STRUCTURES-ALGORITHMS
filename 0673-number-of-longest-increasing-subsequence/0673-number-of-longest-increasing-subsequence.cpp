class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,1);
        vector<int>count(n,1);
        int maxi=1;
        int len=0;
        // int maxi=1;
        

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                  dp[i]=1+dp[j];
                  count[i]=count[j];
                }
                else if(nums[j]<nums[i] && 1+dp[j]==dp[i]){
                    // dp[i]=1+dp[j];
                    // existing and the previous one 
                    count[i]=count[i]+count[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }

        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                len+=count[i];
            }
        }
        

        return len;
    }
};