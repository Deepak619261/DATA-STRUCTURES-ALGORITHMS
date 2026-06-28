class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // slightly better approach 
        if(nums.size()<=1)return nums.size();
        sort(nums.begin(),nums.end());

        int ans=1;
        int count=1;

        for(int i=1;i<nums.size();i++){
        // cout<<"at index "<<i<<" the value are "<<nums[i-1]<<" and "<<nums[i]<<endl;
           if(nums[i]==nums[i-1]+1){
             count++;
           }
           else if(nums[i]==nums[i-1]){
            continue;
           }
           else{
            count=1;
           }
        ans=max(ans,count);
        }
        //  [0,1,1,2]

        return ans;

    }
};