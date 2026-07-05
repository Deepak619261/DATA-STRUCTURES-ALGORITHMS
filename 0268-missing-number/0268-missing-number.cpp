class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorcal=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            xorcal=xorcal^nums[i];
            xorcal=xorcal^i;
        }

        return xorcal^n;
    }
};