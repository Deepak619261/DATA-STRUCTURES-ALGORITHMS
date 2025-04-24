class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        // unordered_map<int,int>mpp;
        int count=0;

        int k=st.size();
        int first=0;
        int second=0;

        int n=nums.size();
        unordered_map<int,int>mpp;

        while(first<n && second<n){
            mpp[nums[first]]++;

            while(mpp.size()==k){
                 count+=nums.size()-first;
                 mpp[nums[second]]--;
                 if(mpp[nums[second]]==0)mpp.erase(nums[second]);
                 second++;
            }
            first++;
             
        }


        return count;

                
    }
};