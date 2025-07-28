class Solution {
public:
    int maxProduct(vector<int>& nums) {
         // maximum sum and maximum product subarray should lead you to the kadane's algo 

         // i saw it from the solution but the here kadane will work from left and right both sides 
         int maxi=INT_MIN;

         int prod=1;

         for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            maxi=max(prod,maxi);
            if(prod==0)prod=1;
         }

         prod=1;

         for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            maxi=max(prod,maxi);
            if(prod==0)prod=1;
         }


         return maxi;
    }
};