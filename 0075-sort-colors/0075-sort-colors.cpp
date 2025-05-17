class Solution {
public:
    void sortColors(vector<int>& nums) {
        // so whenever we got something like that we have to group the same thing together , we the idea dutch flag algorithm comes , here we have to consider three pointers, first , second , third 
        // the dutch flag algo says that we want to have the array someting like this , 0 to low-1 , low to mid-1 and high+1 to n-1 
        // remmeber it 
        int low=0;
        int high=nums.size()-1;
        int mid=0;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low++],nums[mid++]);
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high--]);
            }
        }
    }
};