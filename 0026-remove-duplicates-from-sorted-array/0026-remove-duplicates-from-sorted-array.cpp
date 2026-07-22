class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first=0;
        int second=0;
        int n=nums.size();
        while(first<n && second<n){
            if(nums[first]==nums[second]){
                second++;
            }
            else{
                swap(nums[first+1], nums[second]);
                first++;
                second++;
            }
        }
        return first+1;
    }
};