class Solution {
    int MOD=1e9+7;
    int solve(int index, int n,vector<int>&dp){
        if(index>=n){
            return 1;
        }

        if(dp[index]!=-1)return dp[index];

        // i have two choices that either i can pick that and move i+1 
        // or i don't choose that and move i 
        int first=solve(index+2,n,dp)%MOD;

        int second=solve(index+1,n,dp)%MOD;


        return dp[index]=(first+second)%MOD;

        // in either case i am getting the one valid step 
    }
public:
    int countHousePlacements(int n) {
        //  lets solve if there was only one side of the street 
        vector<int>dp(n,-1);
        int ans=solve(0,n,dp)%MOD;
        long long res=(long long)ans%MOD * (long long)ans%MOD;
        return res%MOD;
    }
};