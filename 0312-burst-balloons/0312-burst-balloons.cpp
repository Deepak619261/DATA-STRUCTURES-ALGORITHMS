class Solution {
    int solve(vector<int>nums,int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        

        if(dp[i][j]!=-1) return dp[i][j];


        int maxi=-1e9;

        for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1]+solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp);
            maxi=max(maxi,coins);
        }

        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {

        int n=nums.size();

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        // as here we are not cutting the stick only we are bursting the ballons so there is no need to sort the nums array 

        //  add dp to it 
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        //  let's do tabulation 


        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){

            int maxi=-1e9;

           for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
            maxi=max(maxi,coins);
        }

        dp[i][j]=maxi;
            }
        }





        return dp[1][n];
        
    }
};