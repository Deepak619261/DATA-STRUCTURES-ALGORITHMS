class Solution {
       int solve(int index, vector<int>&nums,vector<int>&dp,int size){
        if(index>=size)return 0;


        if(dp[index]!=-1)return dp[index];

        // we should not use the INT_MIN as in any case it can just pick the negative value in max value picking so that case 
        // INT_MIN + some negative value --> will cause the overflow 

        //  it can have two choice , it can pick the current one and move index+2 ,
        // or it just don't pick the one and just move one ahead index+1 
        int pick=nums[index]+solve(index+2,nums,dp,size);
        int dontpick=solve(index+1,nums,dp,size);
        
        cout<<"size is "<<size<<" and the value is"<<max(pick,dontpick)<<endl;
        return dp[index]=max(pick,dontpick);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        return max(solve(0,nums,dp,nums.size()-1),solve(1,nums,dp2,nums.size()));
    }
};