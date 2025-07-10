class Solution {
    int MOD=1e9+7;
    int solve(int index,int startPos, int endPos, int k,vector<vector<int>>&dp){
        // solution taken from the solution section 
        if(index==0){
            if(startPos==endPos){
                return 1;
            }
            else {
                return 0;
            }
        }

        // cout<<"["<<index<<"]"<<"["<<endPos<<"]"<<endl;
        if(abs(startPos-endPos)>index)return 0;
        if(dp[index][startPos+1000]!=-1)return dp[index][startPos+1000];

        int left=solve(index-1,startPos-1,endPos,k,dp)%MOD;
        int right=solve(index-1,startPos+1,endPos,k,dp)%MOD;

        return dp[index][startPos+1000]=(left+right)%MOD;

    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int dist=startPos-endPos;
        if(dist>k)return 0;

        vector<vector<int>> dp(k+1, vector<int>(3000, -1));

        return solve(k,startPos,endPos,k,dp);

        // dp[startPos][]

        // what we are doing is that we are assuming we have only k steps  , so we are assigning the index as k , and we are at one index moving to both left and righ both 
        // assuming we are at endpos



    }
};