class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
      int currsum=nums[0];
      int ans=nums[0];

      for(int i=1;i<nums.size();i++){
        if(nums[i]<=nums[i-1]){
            currsum=nums[i];
        }
        else{
            currsum+=nums[i];
        }
        ans=max(ans,currsum);
      }  

      return ans;
    } 
};