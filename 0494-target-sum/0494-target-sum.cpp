class Solution {
    int solve(vector<int>nums,int aim , int index , vector<vector<int>>&dp){
        if(index==0){

            if(aim==0 && nums[0]==0){
                return 2; // will reach the target whther we pick the element or not 
            }
            if(aim==0){
                return 1; // will be counted in not taken case 
            }
            return aim==nums[0]; // if we are picking the element at the zero index 
        }

        if(dp[index][aim]!=-1) return dp[index][aim];


        //  simple approach of take and not take 
        int take=0;
        if(nums[index]<=aim){
        take =solve(nums,aim-nums[index],index-1,dp);
        }
        int nottake=solve(nums,aim,index-1,dp);


        return  dp[index][aim]=take+nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
    
    for(int i:nums){
        sum+=i;
    }

    
    int aim=(target+sum)/2;


    if( (sum+target) % 2!=0 || aim>sum || aim<0) return 0;
    vector<vector<int>>dp(n,vector<int>(aim+1,-1));

    return solve(nums,aim,n-1,dp);
    

    }
};

//     simple explanation of the solution see we have to find the subsequences of the number in which we can put +ve sign and the rest numbers will be assigned the negative numbers 
    // two subsequeneces are such S1+S2=totalSum
    //  we want such subsequences such that S1-S2=target 

    //  solve these two equation simaltaneously so we can exprese one of the subsequence in terms of the totalsum & target 
    // s1=totalsum+target/2 ya phir s2=totalsum-target/2

    //  we can pick any target and simpley count the numbers of subsets equals to target 