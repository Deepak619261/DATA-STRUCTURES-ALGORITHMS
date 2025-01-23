class Solution {
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size()+2,-1);

    dp[nums.size()]=0;
    dp[nums.size()+1]=0;
    
    for(int i=nums.size()-1;i>=0;i--){
        int takesum=nums[i]+dp[i+2];
        int nottakesum=dp[i+1];
        dp[i]=max(takesum,nottakesum);
    }
    return dp[0];
}
public:
    int rob(vector<int>& nums) {
          if(nums.size()==1)return nums[0];

           vector<int>arr1;
           vector<int>arr2;
           for(int i=1;i<nums.size();i++){
            arr1.push_back(nums[i]);
           }

           for(int i=0;i<nums.size()-1;i++){
             arr2.push_back(nums[i]);
           }

           return max(maximumNonAdjacentSum(arr1),maximumNonAdjacentSum(arr2));
    }
};