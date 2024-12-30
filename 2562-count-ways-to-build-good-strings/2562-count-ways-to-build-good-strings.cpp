class Solution {
    const int MOD=1e9+7;
    int solve(int len,int zero ,int one,int currlen,vector<int>&dp){
        // if you look closely its not about strings , its about how much steps/length you are taking 
        // if(currlen==len)return 1;

        if(currlen>=len)return 0;

        if(dp[currlen]!=-1)return dp[currlen];
        

        //  we got two choices either we can pick the zero or we can pick the 

        
        
        
        int pickzero=0;
        int pickone=0;
        
        if(currlen+zero<=len){
        pickzero+=1;
        }

        if(currlen+one<=len){
        pickone+=1;
        }
        
        

        pickzero+=solve(len,zero,one,currlen+zero,dp)%MOD;
        pickone+=solve(len,zero,one,currlen+one,dp)%MOD;

        
        


       
       
       return dp[currlen]=(pickzero+pickone)%MOD;


    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // intution i am getting via seeing the hint is that we should calculate the number of good strings for high+1 and low-1 and return subtractions of both the answer
        

        
        vector<int>dp1(high+1,-1);
        
        int ans1=solve(high,zero,one,0,dp1);
    
        vector<int>dp2(high+1,-1);


        int ans2=solve(low-1,zero,one,0,dp2);

        return (ans1-ans2+MOD)%MOD;
    }
};