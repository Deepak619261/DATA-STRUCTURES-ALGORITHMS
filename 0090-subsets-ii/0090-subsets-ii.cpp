class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        int n =nums.size();
        int count=pow(2,n);

        

        for(int i=0;i<count;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){

                if(i & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        vector<vector<int>>ans(st.begin(),st.end());

        return ans;
    }
};