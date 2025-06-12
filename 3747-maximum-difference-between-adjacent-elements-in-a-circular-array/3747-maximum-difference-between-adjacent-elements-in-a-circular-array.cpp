class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                ans=max(abs(nums[i]-nums[0]),ans);
            }
            else{
                ans=max(ans,abs(nums[i]-nums[i+1]));
            }
        }
        return ans;
    }
};