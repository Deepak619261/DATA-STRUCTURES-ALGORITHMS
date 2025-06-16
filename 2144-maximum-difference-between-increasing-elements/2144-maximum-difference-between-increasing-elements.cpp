class Solution {
public:
    int maximumDifference(vector<int>& nums) {
         int n=nums.size()-2;
int maxi=nums.back();
int ans=-1;

for(int i=n;i>=0;i--){
  if(nums[i+1]>maxi){
   maxi=nums[i+1];
   }

  int diff=maxi-nums[i];
  if(diff>0)ans=max(ans,diff);

  if(maxi>nums[i]){
    nums[i]=maxi;
  }

} 

return ans;
  
    }
    
};