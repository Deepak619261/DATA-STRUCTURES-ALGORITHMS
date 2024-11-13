class Solution {
public:
    bool check(vector<int>& nums) {
        //  count pivot elements 
        int count=0;
        if(nums.size()==1) return true;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) count++;
        }

        if(nums.back()>nums[0] && count!=0) count++;

        if(count>1) return false;
        return true;
    }
};