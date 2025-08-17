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
        //  second approach is via bit manipulation 
        //  there will be subsets 2^n with the empty set including 
        int n =nums.size();
        int count=pow(2,n);

        
        vector<vector<int>>ans;

        for(int i=0;i<count;i++){
            // now we are getting something like 
            //  000,001, 010,011,100,101,110,111
            //  we have to see the indices of 1's in every num and pick that one number only 
            //  what we will do , we'll take the 1 and we will left shit it number of times of digits presents 
            vector<int>temp;
            for(int j=0;j<n;j++){

                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};