class Solution {
    private:
    void solve(vector<int>nums,vector<int>&ds, vector<vector<int>>&ans,map<int,bool>mpp,int index){
        if(index==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mpp[i]){
                mpp[i]=true;
                ds.push_back(nums[i]);
                solve(nums,ds,ans,mpp,index+1);
                ds.pop_back();
                mpp[i]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //  the new approach according to striver's
        map<int,bool>mpp;
        vector<int>ds;
        vector<vector<int>>ans;
        solve(nums,ds,ans,mpp,0);
        return ans;
    }
};