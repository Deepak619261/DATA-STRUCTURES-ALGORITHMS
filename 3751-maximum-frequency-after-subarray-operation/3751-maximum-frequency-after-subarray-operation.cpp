class Solution {

    int maximumsubarray(vector<int>&nums, int val,int k){
        int curr=0;
        int maxi=0;

        // one edge case that val and k can be same at the same time so we will not use else if structure

        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                curr++;
            }
            if(nums[i]==k){
                curr--;
            }
            if(curr<0)curr=0;
            maxi=max(curr,maxi);
        }

        return maxi;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        // solution i saw from the video and 
        // the time less than O(n^2) but more than O(N) ..we can say at worst case it will be O(N*50)  
        // the main catch here is the nums[i] range which is from 1 to 50 , this is the point 
        // as we know that we want to increment the most frequent element in any subarray 
        // but the thing is that value which matches with the k may be more than once and at different positions , so we would have to check the maximum subarray sum for all the distinct elements prsent in array , as we can't traverse staright because there can be k value in nums at different positions 
        // so for getting maximum subarray ,(frequency element) -> we will count only that element other elements as -1 , and will apply the kadane's algorithm 
        unordered_map<int,int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }

        int maxi=0;



        for(auto it:mpp){
            int check=maximumsubarray(nums,it.first,k);
            maxi=max(check,maxi);
        }


        return mpp[k]+maxi;
    }
};