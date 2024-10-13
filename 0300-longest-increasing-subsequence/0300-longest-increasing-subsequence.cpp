class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //  tabulation solution 
        //  let's space optimize this 
        int n=nums.size();
        vector<int>prev(n+1,0);
       
        for(int i=n-1;i>=0;i--){
            vector<int>curr(n+1,0);
            for(int j=i-1;j>=-1;j--){
                int pick=0;
                if(j==-1 || nums[i]>nums[j]){
                    pick=1+prev[i+1];
                }
                int notpick=prev[j+1];

                curr[j+1]=max(pick, notpick);
            }
            prev=curr;
        }

        return prev[0];

        
    }
};