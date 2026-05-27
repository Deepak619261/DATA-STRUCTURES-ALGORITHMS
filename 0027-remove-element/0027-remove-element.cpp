class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int h =nums.size()-1;
        int l=0;
        while(l<=h){
            if(nums[l]==val){
                swap(nums[l],nums[h]);
                h--;
            }
            else{
                l++;
            }
        }
        return l;
    }
};