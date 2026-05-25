class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int currMax=nums[0];
        int currMin=nums[0];
        int ans=currMax;

        for(int i=1;i<nums.size();i++){
            int maxi=max(nums[i],max(currMax*nums[i],currMin*nums[i]));
            int mini=min(nums[i],min(currMax*nums[i],currMin*nums[i]));
            currMax=maxi;
            currMin=mini;
            ans=max(ans,currMax);
        }
        return ans;
    }
};