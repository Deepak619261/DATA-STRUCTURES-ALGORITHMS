class Solution {
    int solve(int index, vector<int>&nums,int xorv,unordered_map<int,int>&mpp){
        if(index==nums.size()){
            mpp[xorv]++;
            return 0;
        }

        // select
        int take=solve(index+1,nums,xorv|nums[index],mpp);
        // dontselect
        int donttake=solve(index+1,nums,xorv,mpp);

        return max(take, donttake);

    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // store all the subset -> calculate their bitwise OR and store that in map or something (bitwiseOR -> count)

        unordered_map<int,int>mpp;

        solve(0,nums,0,mpp);

        int ans=0;
        int xorv=0;

        for(auto it:mpp){
            if(it.first>xorv){
                xorv=it.first;
                ans=it.second;
            }
        }

        return ans;
        
    }
};