class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();

        int maxi=INT_MIN;
        int cnt=0;

        for(auto it:nums){
            if(it==maxi){
                // maxi=it;
                cnt++;
            }
            else if(it>maxi){
                maxi=it;
                cnt=1;
            }
        }
        // return maxi;

        int count=0;
        int right=0;
        int left=0;
        int len=0;
        
        while(left<n && right<n){
            if(nums[right]==maxi)count++;

            while(count>=k){
                len++;
                if(nums[left]==maxi)count--;
                left++;
            }
            ans+=len;
            right++;
        }

        return ans;

        
    }
};