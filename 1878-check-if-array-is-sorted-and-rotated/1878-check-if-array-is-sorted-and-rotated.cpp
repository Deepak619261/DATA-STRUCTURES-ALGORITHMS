class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()<=2)return true;

        int cnt=0;

        if(nums[0]<nums.back())cnt++;


        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])cnt++;
        }


        return cnt<=1;
    }
};