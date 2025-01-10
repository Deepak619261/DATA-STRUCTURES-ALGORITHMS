class Solution {
    int solve(vector<int>nums, int index, int prev_index,vector<vector<int>>&dp){
        if(index==nums.size()){
            return 0;
        }
        
        if(dp[index][prev_index+1]!=-1){
            return dp[index][prev_index+1];
        }

        //  there will be two cases eitheir pick or not pick 
        int notpick=solve(nums,index+1, prev_index,dp);

        int pick=0;

        //  don't pick
        if(prev_index==-1 || nums[index]>nums[prev_index]){
           pick=1+solve(nums,index+1,index,dp); 
        }


        return dp[index][prev_index+1]=max(pick,notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //  let's tabulate the solution 

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=-1;j--){
                int not_pick=dp[i+1][j+1];
                int pick=0;
                if(j==-1 || nums[i]>nums[j]){
                    pick=1+dp[i+1][i+1];
                }

                dp[i][j+1]=max(pick,not_pick);
            }
        }

        
        return dp[0][0];
    }
};