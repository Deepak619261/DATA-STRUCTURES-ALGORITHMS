class Solution {
    bool isincreasing(int l, int r, vector<int>&nums){
        for(int i=l;i<l+r-1;i++){
            if(nums[i]>=nums[i+1])return false;
        }

        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2*k)return false;

        for(int i=0;i<=n-2*k;i++){
            if(isincreasing(i,k,nums) && isincreasing(i+k,k,nums))return true;
        }

        return false;

    }
};