class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);

        //  precompute the maximum element for each subarray 

        vector<vector<int>>maxi(n,vector<int>(n,INT_MIN));

        for(int i=0;i<n;i++){
            maxi[i][i]=arr[i];
        }
        

        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
               
                maxi[i][j]=max(maxi[i][j-1],arr[j]);
            }
        }


        for(int i=n-1;i>=0;i--){
            
        int lim=min(i+k,n);
        int ans=INT_MIN;
        for(int j=i;j<lim;j++){
            int maxele=maxi[i][j];
            int sum=(j-i+1)*maxele+dp[j+1];
            ans=max(sum,ans);
        }




        dp[i]=ans;

        }

        return dp[0];
    }
};