class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //  simple binary search 
        int s=0;
        int e=nums.size()-1;

        int mid=s+(e-s)/2;
        int index=-1;

        while(s<=e){
             if(nums[mid]==target){
                return mid;
             }

             if(nums[mid]<=target){
                index=mid;
                s=mid+1;
             }
             else{
                e=mid-1;
             }




             mid=s+(e-s)/2;
        }

        return index+1;
    }
};