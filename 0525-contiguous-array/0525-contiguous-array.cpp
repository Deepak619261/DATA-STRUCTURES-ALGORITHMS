class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // this problem boils down to the longest subarray with given sum -> we just have to consider the 0 as -1 
        map<int,int>mpp;
        int maxi=0;

        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum++;
            }
            else{
                sum--;
            }
            
            if(sum==0)maxi=max(maxi,i+1);

            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }
            
            if(mpp.find(sum)==mpp.end()){
                    mpp[sum]=i;
            }
            
        }

        return maxi;

    }
};