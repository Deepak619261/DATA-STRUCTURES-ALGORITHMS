class Solution {
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }
        if(a==0)return b;
        return a;
    }
public:
    int findGCD(vector<int>& nums) {

        int mini=nums[0];
        int maxi=nums[0];

        for(auto it:nums){
           maxi=max(it,maxi);
           mini=min(it,mini);
        }

        return gcd(maxi,mini);
        
    }
};