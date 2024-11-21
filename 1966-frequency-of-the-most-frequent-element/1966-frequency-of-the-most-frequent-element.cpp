class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // the disadvantage of doing any sheet is that you first look on the topic the question is from which so it never helps in problem solving 

        sort(nums.begin(),nums.end());
        long long sum =0;
        int left=0;
        int right=0;

        int result=0;

        while(right<nums.size()){
            sum+=nums[right];
            long long req_cost=(long long)nums[right]*(right-left+1);
            while(req_cost-sum>k && left<=right){
                sum-=nums[left];
                left++;
                req_cost=(long long)nums[right]*(right-left+1);
            }
            result=max(result,right-left+1);
            right++;
        }

        

        return result;
    }
};