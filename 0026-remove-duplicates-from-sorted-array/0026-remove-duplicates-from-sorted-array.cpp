class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first=0;
        int second=1;

        while(first<nums.size() && second<nums.size()){
            if(nums[first]==nums[second]){
                second++;
            }
            else{
                nums[first+1]=nums[second];
                second++;
                first++;
            }
        }

        return first+1;
    }
};