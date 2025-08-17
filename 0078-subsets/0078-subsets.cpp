class Solution {
    void solve(int index,vector<vector<int>>&ans, vector<int>temp, vector<int>&nums){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        // on every index , we have two choice , either pick the current element or don't 
        temp.push_back(nums[index]);
        solve(index+1,ans,temp,nums);
        temp.pop_back();

        solve(index+1,ans,temp,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //  lets go with very straight forward 
        vector<vector<int>>ans;


        solve(0,ans,{},nums);
        return ans;
    }
};