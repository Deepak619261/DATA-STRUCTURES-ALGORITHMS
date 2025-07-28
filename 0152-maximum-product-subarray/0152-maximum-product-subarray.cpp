class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //  we will go with the very brute force way firstly 
        int maxProd=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int currprod=1;
            for(int j=i;j<n;j++){
               currprod*=nums[j];
               maxProd=max(currprod,maxProd);
            }
        }

        return maxProd;
    }
};