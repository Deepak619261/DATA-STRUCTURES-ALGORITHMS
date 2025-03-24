class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>temp(n+1,0);

        for(auto it:queries){
            temp[it[0]]++;
            temp[it[1]+1]--;
        }

        int op=0;
        for(int i=0;i<nums.size();i++){
            op+=temp[i];
            if(op<nums[i])return false;
        }
        return true;
    }
};