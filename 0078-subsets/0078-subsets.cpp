class Solution {
    void solve(int index,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }

        // at every step i have two option , either i can take the current entry or i can't 

        solve(index+1,nums,temp,ans);

        temp.push_back(nums[index]);
        solve(index+1,nums,temp,ans);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,nums,temp,ans);
        return ans;
    }
};