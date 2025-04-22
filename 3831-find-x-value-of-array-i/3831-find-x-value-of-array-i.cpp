class Solution {
    long long solve(int index, int req,long long prod, vector<int>&nums,int k,vector<vector<long long>>&dp){
        if(index==nums.size())return 0;

        if(dp[index][prod+1]!=-1)return dp[index][prod+1];

        long take=0;
        long donttake=0;
        int count=0;

        //  basic thought process is that two cases are there , first that we are starting the subarray , there may be two cases , where we can take up the current element or we can't same applies to the other case 

        if(prod==-1){
            // means  we are just starting the contigous subarray , 
            if(nums[index]%k==req){
                count=1;
            }
            take=count+solve(index+1,req,nums[index],nums,k,dp);
            donttake=solve(index+1,req,-1,nums,k,dp);
        }
        else{
            long long newprod=prod*nums[index];
            newprod=newprod%k;
            if(newprod==req){
                count=1;
            }
            take=count+solve(index+1,req,newprod,nums,k,dp);
            
        }

        return dp[index][prod+1]=take+donttake;
    }
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // i did this question by seeing the solution of someone , i understood the core logic but wasn't able to run properly without seeing ,like there were some mistakes 
        vector<long long>ans(k,0);
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]%k;
        }


    

        for(int i=0;i<k;i++){
            vector<vector<long long>>dp(n,vector<long long>(k+1,-1));
            ans[i]=solve(0,i,-1,nums,k,dp);
        }

        return ans;
    }
};