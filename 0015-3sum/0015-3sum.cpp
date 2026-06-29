class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // sort the array -> O(nlogn)


        vector<vector<int>>ans;

        for(int i=0;i<nums.size();i++){

            if (i > 0 && nums[i] == nums[i-1])
        continue;
            int s=i+1;
            int e=nums.size()-1;

            while(s<e){
                int sum=nums[i]+nums[s]+nums[e];
                vector<int>temp={nums[i],nums[s],nums[e]};
                if(sum==0){
                    s++;
                    e--;
                    ans.push_back(temp);
                       // Skip duplicate second elements
                    while (s < e && nums[s] == nums[s - 1])
                        s++;

                    // Skip duplicate third elements
                    while (s < e && nums[e] == nums[e + 1])
                        e--;
                }
                else if(sum<0){
                    s++;
                }
                else{
                    e--;
                }
            }
        }

        return ans;
    }
};