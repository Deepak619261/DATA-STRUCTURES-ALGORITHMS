class Solution {
    int MOD=1e9+7;
    // int solve(int index,int startPos, int endPos, int k,vector<vector<int>>&dp){
    //     // solution taken from the solution section 
    //     if(index==0){
    //         if(startPos==endPos){
    //             return 1;
    //         }
    //         else {
    //             return 0;
    //         }
    //     }

    //     // cout<<"["<<index<<"]"<<"["<<endPos<<"]"<<endl;
    //     if(abs(startPos-endPos)>index)return 0;
    //     if(dp[index][startPos+1000]!=-1)return dp[index][startPos+1000];

    //     int left=solve(index-1,startPos-1,endPos,k,dp)%MOD;
    //     int right=solve(index-1,startPos+1,endPos,k,dp)%MOD;

    //     return dp[index][startPos+1000]=(left+right)%MOD;

    // }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int dist=abs(startPos-endPos);
        if(dist>k)return 0;

        int minP = startPos - k;
        int maxP = startPos + k;
        int width = maxP - minP + 1;

        vector<vector<int>> dp(k+2, vector<int>(width, 0));
        dp[0][startPos-minP]=1;

        for(int index=1;index<=k;index++){
            for(int startpos=minP;startpos<=maxP;startpos++){
                if(abs(startpos-endPos)>(k - index)){
                    continue;
                }

                int left=0;
                int right=0;

                if(startpos-1>=minP){
                    left+=dp[index-1][(startpos-1)-minP]%MOD;
                }
                if(startpos+1<=maxP){
                    right+=dp[index-1][(startpos+1)-minP]%MOD;
                }

                dp[index][startpos-minP]=(left+right)%MOD;

            }
        }

        return dp[k][endPos-minP];

        

        // dp[startPos][]

        // what we are doing is that we are assuming we have only k steps  , so we are assigning the index as k , and we are at one index moving to both left and righ both 
        // assuming we are at endpos



    }
};