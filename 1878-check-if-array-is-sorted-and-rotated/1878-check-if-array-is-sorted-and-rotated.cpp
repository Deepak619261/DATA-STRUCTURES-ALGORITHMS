class Solution {
public:
    bool check(vector<int>& nums) {

        if(nums.size()==1)return true;
        
        int count=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])count++;
        }

        if(nums[0]<nums.back())count++;

        // for a array to be sorted in non decreasing pair , there can exist at most one inversion pair , because suppose we got first inversion pair in middle that means that is the starting point of sorted array and think in cyclic manner then there should not exist any inversion pair in the array and the first element shoudl be greater than the last as we have already found one inversion pair and if by chance we get more than one inversion pair than we can sort the array by rotating it , there can be zero inversion pair if there are same elements 
        return count<=1;        


    }
};