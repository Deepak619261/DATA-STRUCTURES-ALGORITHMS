class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());

        int longest=0;
        

        for(auto it:st){
            int count=1;
            if(!st.count(it-1)){
               int val=it;
               while(st.count(val+1)){
                 val=val+1;
                 count++;
               }
            }
            longest=max(count,longest);
            count=1;
        }

        return longest;
    }
};