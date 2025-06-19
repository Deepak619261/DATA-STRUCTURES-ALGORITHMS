class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // the intution is that subsequence means not taking the elements with some missing but should be samee , order but if we carefully read the questions its all about maxi and mini element , so we don't have to take stress about the order at all 
        sort(nums.begin(),nums.end());
        int maxi=nums[0];
        int mini=nums[0];
        int count=0;

        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            if(maxi-mini>k){
                count++;
                maxi=nums[i];
                mini=nums[i];
            }
        }

        return count+1;
    }
};