class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // exact similar problem 
        // by defintion -> median is the integer that is defined for all the integers has minimum abs diff
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int median=nums[len/2];
        int count=0;
        for(auto it:nums){
           count+=abs(it-median);
        }

        return count;
    }
};