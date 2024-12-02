class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int,int>mpp;
        long long sum=0;

        for(auto it : nums){
            sum+=it;
            mpp[it]++;
        }

        int ans=INT_MIN;

        for(auto x:nums){
            int remaining=sum-x;
            // intution is simple if firstly if we are correctly pointing out the outlier then the total sum will be evern as it will a+b+c = sum and c=sum and 2c , and if removing the outlier and half of the sum _> exist in the remaining array then it is the outlier 
            mpp[x]--;
            if(mpp[x]==0) mpp.erase(x);
            if(remaining%2==0 && mpp.find(remaining/2)!=mpp.end()){
                ans=max(ans,x);
            }
            mpp[x]++;
        }

        return ans;
    }
};