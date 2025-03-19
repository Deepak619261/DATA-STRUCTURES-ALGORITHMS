class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op=0;
        int n=nums.size();

        for(int i=0;i<n-2;i++){
            if(nums[i]==1)continue;
            else{
                nums[i]=1;
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                op++;
            }
        }

        if(!nums[n-1] || !nums[n-2] || !nums[n-3]){
            return -1;
        }

        return op;

    }
};