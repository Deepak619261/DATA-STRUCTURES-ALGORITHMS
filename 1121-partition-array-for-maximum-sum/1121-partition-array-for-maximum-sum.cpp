class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);

        //  precompute the maximum element for each subarray 


        for(int i=n-1;i>=0;i--){
            
        int lim=min(i+k,n);
        int ans=INT_MIN;
        int maxele=INT_MIN;
        for(int j=i;j<lim;j++){
            maxele=max(maxele,arr[j]);
            int sum=(j-i+1)*maxele+dp[j+1];
            ans=max(sum,ans);
        }




        dp[i]=ans;

        }

        return dp[0];
    }
};