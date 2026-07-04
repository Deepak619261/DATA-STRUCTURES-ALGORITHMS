class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //  we can use the floyd cycle detection algo here 
        int fast=nums[0];
        int slow=nums[0];


        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(fast!=slow);

        slow=nums[0];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }

        return fast;




    }
};