class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        int last=INT_MIN;


        //  saw its approach fromt the solution i understood the solution but partially , 
        

        for(auto it:nums){
            int newpos=max(last+1,it-k);
            if(newpos<=it+k){
                st.insert(newpos);
                last=newpos;
            }

        }

        return st.size();
    }
};