class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //  the basic intution here is that for sure we won't like to take a target to make all elements equal outside of a nums for sure
        int left=0;
        long long sum=0;
        int ans=0;
        sort(nums.begin(),nums.end());

        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            // long long req=(long long)(right-left+1)*(long long)nums[right]-sum;

            while((long long)(right-left+1)*(long long)nums[right]-sum>k && left<nums.size()){
                sum-=nums[left];
                left++;
            }

            ans=max(ans,right-left+1);
            
        }
        return ans;
    }
};