class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // thing is if you look carefully then we want to maximize the overall value so for that we want to maximize the nums[i]
        int n=nums.size();

        long long ans=0;

        int maxi=nums[0];

        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                long long check=(maxi-nums[j]);
                check=check*nums[k];
                cout<<check<<"->"<<j<<","<<k;
                if(check>0)ans=max(check,ans);
                maxi=max(maxi,nums[j]);
            }
        }

        return ans;


    }
};