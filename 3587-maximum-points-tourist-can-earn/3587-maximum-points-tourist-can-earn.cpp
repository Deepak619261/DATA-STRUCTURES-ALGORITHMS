class Solution {
    int solve(int city , int day ,vector<vector<int>>&stayScore,vector<vector<int>>&travelScore,int n , int k,vector<vector<int>>&dp){
        if(city>=n || day>=k)return 0; // base case

        // on every day we got two choices either we can stay in the city or we can move to another city -> means he can go to any city , means he can go to the city that he came from just now if he want 

        if(dp[city][day]!=-1)return dp[city][day];

        int stay=stayScore[day][city]+solve(city,day+1,stayScore,travelScore,n,k,dp);
        int move=INT_MIN;

        for(int i=0;i<n;i++){
            if(i==city)continue;
            int check=travelScore[city][i]+solve(i,day+1,stayScore,travelScore,n,k,dp);
            move=max(check,move);
        }


        return dp[city][day]=max(stay,move);
    }
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans=INT_MIN;


        vector<vector<int>>dp(n+1,vector<int>(k+1,0));

        for(int day=k-1;day>=0;day--){
            for(int city=n-1;city>=0;city--){


        int stay=stayScore[day][city]+dp[city][day+1];
        int move=INT_MIN;

        for(int i=0;i<n;i++){
            if(i==city)continue;
            int check=travelScore[city][i]+dp[i][day+1];
            move=max(check,move);
        }


        dp[city][day]=max(stay,move);

            }
        }

        for(int i=0;i<n;i++){
        ans=max(ans,dp[i][0]);
        }

        return ans;
    }
};