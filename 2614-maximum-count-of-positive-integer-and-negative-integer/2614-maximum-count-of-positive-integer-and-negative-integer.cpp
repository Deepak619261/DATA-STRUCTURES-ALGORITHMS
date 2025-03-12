class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ans=0;

        int poscnt=0;
        int negcnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                poscnt++;
            }
            else if(nums[i]<0){
                negcnt++;
            }
            ans=max(ans,max(poscnt,negcnt));
        }
        return ans;
    }
};