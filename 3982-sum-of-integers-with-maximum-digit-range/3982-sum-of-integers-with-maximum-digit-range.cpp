class Solution {
    int maxdigitrange(vector<int>&nums){
        int maxi=INT_MIN;

        for(auto it:nums){
            maxi=max(maxi,digitrange(it));
        }

        return maxi==INT_MIN?0:maxi;

    }

    int digitrange(int num){
        int maxi=INT_MIN;
        int mini=INT_MAX;

        while(num){
            int digit=num%10;
            maxi=max(maxi,digit);
            mini=min(mini,digit);
            num=num/10;
        }
        if(maxi!=INT_MIN && mini!=INT_MAX)return (maxi-mini);
        return 0;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int sum=0;

        int maxi=maxdigitrange(nums);

      

        for(auto it:nums){
            if(digitrange(it)==maxi){
               sum+=it;
            }
        }

        return sum;
    }
};