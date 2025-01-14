class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=0;
        int curr=prev+1;

        while(prev<nums.size() && curr<nums.size()){
            if(nums[prev]==nums[curr]){
                curr++;
            }
            else{
                nums[prev+1]=nums[curr];
                curr++;
                prev++;
            }
        }

        return prev+1;
    }
};