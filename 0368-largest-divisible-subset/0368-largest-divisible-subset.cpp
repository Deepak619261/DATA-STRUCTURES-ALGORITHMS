class Solution {
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int>dp(n,1);
        vector<int>hash(n,1);


        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                //  consider j-> previndex 
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
        }

        vector<int>res;
        
        //  search the largest index 
        int ans=-1;
        int lastindex=-1;

        for(int i =0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastindex=i;
            }
        }

        res.push_back(nums[lastindex]);

        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            res.push_back(nums[lastindex]);
        }


        return res;
    }
};