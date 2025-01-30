class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //  going bia prefix sum approach 
        map<int,int>mpp;
        int count =0;
        int presum=0;
        // mpp[0]=1;

        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            if(presum==k){count++;}
            int to_remove=presum-k;
            count+=mpp[to_remove];
            mpp[presum]+=1;
        }

        return count;
    }
};