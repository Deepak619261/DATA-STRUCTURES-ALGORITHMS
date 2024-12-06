class Solution {
    int solve(int index, vector<int>&nums,int k , int op1, int op2,vector<vector<vector<int>>>&dp){
        if(index>=nums.size()){
            return 0;
        }

        if(dp[index][op1][op2]!=-1) return dp[index][op1][op2];
        
        // take the current element 
        int sum=nums[index]+solve(index+1,nums,k,op1,op2,dp);

        //  first try with the first op
        if(op1>0){
            sum=min(sum,(nums[index]+1)/2 + solve(index+1,nums,k,op1-1,op2,dp));
        }

        if(op2>0 && nums[index]>=k){
            sum=min(sum,nums[index]-k+solve(index+1,nums,k,op1,op2-1,dp));
        }

        //  try both in different order 
        if(op1>0 && op2>0 && nums[index]>=k){
            int secondopres=nums[index]-k;
            if(op1>0){
                sum=min(sum,(secondopres+1)/2+solve(index+1,nums,k,op1-1,op2-1,dp));
            }
        }

        if(op1>0 && op2>0){
            int firstopres=(nums[index]+1)/2;
            if(op2>0 && firstopres>=k){
                sum=min(sum,firstopres-k+solve(index+1,nums,k,op1-1,op2-1,dp));
            }
        }

        return  dp[index][op1][op2]=sum;

    }
    
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        //  we have to first prepare a recurrsive solution 
        //  i saw the solution in the discuss section then i am trying this appraoch , i was not able to do this on my own ,i want to be honest here 
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return solve(0,nums,k,op1,op2,dp);
    }
};