class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // vector<vector<int>>ans;

        set<vector<int>>st;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                unordered_set<long long>seen;
                for(int k=j+1;k<nums.size();k++){
                    long long required=(long long)target-nums[i]-nums[j]-nums[k];

                    if(required >= INT_MIN && required <= INT_MAX &&seen.count((int)required)){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)required};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    seen.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());

        return ans;

    }
};