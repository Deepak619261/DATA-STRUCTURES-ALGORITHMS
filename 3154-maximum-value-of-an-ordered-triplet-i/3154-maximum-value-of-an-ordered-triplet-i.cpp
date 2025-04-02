class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // watched from editorial -> 
        // we want that the first thing should be maximized nums[i]-nums[j] 
        int currMaxnum=0;
        int currMaxdiff=0;
        long long ans=0;
        for(int k=0;k<nums.size();k++){
            ans=max((long long)nums[k]*currMaxdiff,ans);
            currMaxnum=max(nums[k],currMaxnum);
            currMaxdiff=max(currMaxdiff,currMaxnum-nums[k]);
        }

        return ans;
    }
};