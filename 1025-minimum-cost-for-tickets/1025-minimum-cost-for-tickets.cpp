class Solution {
    int solve(int currday , set<int>&st , vector<int>&costs ,int lastday ,vector<int>&dp){
             if(currday>lastday)return 0;

             if(dp[currday]!=-1)return dp[currday];
            
            int price=INT_MAX;

            //   take first cost 
            int firstway=costs[0]+solve(currday+1,st,costs,lastday,dp);

            int secondway=costs[1]+solve(currday+7,st,costs,lastday,dp);

            int thirdway=costs[2]+solve(currday+30,st,costs,lastday,dp);

            int fourthway=INT_MAX;

            if(!st.count(currday)){
                fourthway=min(fourthway,solve(currday+1,st,costs,lastday,dp));
            }

            price=min(price,min(firstway,min(secondway,thirdway)));
            price=min(price,fourthway);

            return dp[currday]=price;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // i am going to solve this question no matter how much time it takes 
        // i am writing what i am able to think that , if the day is in the days list then we have three options -> cost[0],cost[1] and cost[2]
        // however if it is not a day given in array , like its the day between the days then then we have four choics-> cost[0],cost[1] and cost[2] or even don't buy the ticket 
        // for checking that days is in the array i will contain the days in set ds 
        int lastday=days.back();
        int currday=days[0];

        set<int>st(days.begin(),days.end());

        vector<int>dp(366,-1);

        return solve(currday,st,costs,lastday,dp);
    }
};