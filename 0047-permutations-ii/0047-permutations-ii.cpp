class Solution {
    void solve(int index, vector<int>&nums,set<vector<int>>&mpp){
        if(index==nums.size()){
            mpp.insert(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(index+1,nums,mpp);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // use the same approach of the solution used and just use the set 
        set<vector<int>>st;
        solve(0,nums,st);

        vector<vector<int>>res;
        for(auto it:st){
            res.push_back(it);
        }

        return res;
        
    }
};