class Solution {
    void solve(int index, vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
        
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1])continue;
                cout<<"heythere";
                temp.push_back(nums[i]);
                solve(i+1,nums,temp,ans);
                temp.pop_back();   
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};