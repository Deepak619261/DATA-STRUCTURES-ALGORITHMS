class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int ele=nums[0];

        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
               ele=nums[i];
               count++;
            }
            else{
                if(count==0){
                    ele=nums[i];
                    count++;
                }
                else{
                    count--;
                }

            }
        }

        return ele;
    }
};