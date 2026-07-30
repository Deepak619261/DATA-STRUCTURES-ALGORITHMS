class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //  lets go via the brute force first 
        // set<vector<int>>st;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int s=j+1;
                int e=nums.size()-1;
                long long targetdash=(long long)target-(long long)nums[i]-(long long)nums[j];

                while(s<e){
                long long sum=(long long)nums[s]+(long long)nums[e];
                

                if(sum<targetdash){
                    s++;
                }
                else if(sum>targetdash){
                    e--;
                }
                else if(nums[s]+nums[e]==targetdash){
                  ans.push_back({nums[i],nums[j],nums[s++],nums[e--]});
                  while(s!=i+1 && s<e && nums[s]==nums[s-1]){
                    s++;
                }

                while(e!=nums.size()-1 && s<e && nums[e]==nums[e+1]){
                    e--;
                }
                }
                }
            }
        }

        // vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};