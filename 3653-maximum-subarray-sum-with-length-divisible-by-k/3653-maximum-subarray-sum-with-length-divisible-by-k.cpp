class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //  approach taken from the solution section 
        //  so what we are doing that we are taking a array of size k 
        // we are storing sum till min(i+k,i+2k ,i+3k)
        //  we are taking min , because we want the maximum sum 
        long long MAXI=1e17;

        vector<long long >store(k,MAXI);
        long long ans=-MAXI;
        long long currsum=0;

        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];

            ans=max(ans,currsum-store[i%k]);

            if((i+1)%k==0){
                ans=max(ans,currsum);
            }




            store[i%k]=min(store[i%k],currsum);
        }


        return ans;
    }
};