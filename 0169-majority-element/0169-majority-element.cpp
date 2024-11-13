class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=-1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans){
                cnt++;
            }
            else if(cnt==0){
                ans=nums[i];
                cnt=1;
            }
            else{
                cnt--;
            }
        }

        return ans;
        
    }
};