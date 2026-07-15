class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<nums.size();i++){

            if(i!=0 && nums[i]==nums[i-1])continue;
            int ele=nums[i];
            int target=0-nums[i];

            int s=i+1;
            int e=nums.size()-1;
            while(s<e){
                int sum=nums[s]+nums[e];

               

                if(sum<target){
                    s++;
                }
                else if(sum>target){
                    e--;
                }
                else if(nums[s]+nums[e]==target){
                  ans.push_back({ele,nums[s++],nums[e--]});
                
                
                while(s!=i+1 && s<e && nums[s]==nums[s-1]){
                    s++;
                }
                while(e!=nums.size()-1 && s<e && nums[e]==nums[e+1]){
                    e--;
                }
                
                }
            }
        }

        return ans;
    }
};