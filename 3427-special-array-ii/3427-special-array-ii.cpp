class Solution {
    int parity(int num){
        if(num%2==0)return 1;
        else return 2;
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>prefixSum(nums.size(),0);

        for(int i=1;i<nums.size();i++){
           prefixSum[i] += prefixSum[i-1];
           if(parity(nums[i])==parity(nums[i-1]))prefixSum[i]++;
        }
        vector<bool>ans;
        for(auto it:queries){
            if(prefixSum[it[1]]-prefixSum[it[0]]==0){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }


        return ans;

    }
};