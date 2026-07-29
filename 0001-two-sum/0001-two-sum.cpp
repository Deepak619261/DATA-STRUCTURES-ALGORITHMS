class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //the very brute force that comes to mind is O(n^2)

        // vector<int>ans;

        // for(int i =0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }

        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            if(mpp.contains(target-nums[i])){
               return {i,mpp[target-nums[i]]};
            }
            else{
                mpp[nums[i]]=i;
            }
        }

        return {};
    }
};