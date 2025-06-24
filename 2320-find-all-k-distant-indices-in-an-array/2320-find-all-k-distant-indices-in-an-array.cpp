class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int>st;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                //  insert from that index to max(0,i-k)
                int lowerlim=max(0,i-k);
                int j=i;
                while(j>=lowerlim){
                    st.insert(j--);
                }
                j=i+1;
                // insert from that index+1 to min(nums.len,index+k)
                int upperlim=min((int)nums.size()-1,i+k);
                while(j<=upperlim){
                    st.insert(j++);
                }
            }
        }

        vector<int>ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};