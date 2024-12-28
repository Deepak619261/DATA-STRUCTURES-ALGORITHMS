class Solution {
    int solve(int index, int rem,vector<int>&sum,vector<vector<int>>&dp,int k){
        if(rem==0)return 0;

        if(index>=sum.size()){
            if(rem>0)return INT_MIN;
            return 0;
        }

        if(dp[index][rem]!=-1)return dp[index][rem];

        //  we got two choices here , either we pick the current index or we don't 

        int pick=sum[index]+solve(index+k,rem-1,sum,dp,k);

        int dontpick=solve(index+1,rem,sum,dp,k);

        return dp[index][rem]=max(pick,dontpick);
    }

    void dfs(vector<int>&sum,int k, int index, int rem, vector<int>&ans,vector<vector<int>>&dp){
        if(rem==0)return;
        if(index>=sum.size())return ;

        int currentIndex=sum[index]+solve(index+k,rem-1,sum,dp,k);
        int skipcurrent=solve(index+1,rem,sum,dp,k);

        if(currentIndex>=skipcurrent){
            ans.push_back(index);
            dfs(sum,k,index+k,rem-1,ans,dp);
        }else{
            dfs(sum,k,index+1,rem,ans,dp);
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //  i am doing this question by seeing its solution and even i am not able to dry run this but i got the idea 
        //  we will use DP here , what we are doing that , we are first , storing the sum of k-sized window here , then we will take decsion whehter to take the current subarray or not , honestly , i understood the approach , but didn't dry run this , and have little confusion in reconstruction of the aray although i have done this reconstrcution type problems earlier in striver's sheet A2Z
        //  create a vector 
        int n=nums.size();
        int size=n-k+1;
        vector<int>sum(size);

        int currsum=0;
        for(int i=0;i<k;i++){
            currsum+=nums[i];
        }
        sum[0]=currsum;

        for(int i=k;i<nums.size();i++){
            currsum=currsum+nums[i]-nums[i-k];
            sum[i-k+1]=currsum;
        }

        vector<int>ans;

        vector<vector<int>>dp(size,vector<int>(4,-1));

        solve(0,3,sum,dp,k);


        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        dfs(sum,k,0,3,ans,dp);


        return ans;
    }
};