class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // for normal part we can put the kadane's algo 
        // circular means the array appended at the last of the array it self 
        // there may be only two case one is max subarray is middle of the array 
        // second is prefix + suffix -> we are picking the some part of the last of array and front part 
        // lets say totalsum =total sum of array 
        // included sum -> part we will take 
        // exluded part -> included part =totalsum-excludedsum 
        // for included part to be as large as possible we need excludedsum as small as 
        int kadaneMax=INT_MIN;
        int sum=0;
        int totalsum=0;
        for(auto it:nums){
            totalsum+=it;
            sum+=it;
            kadaneMax=max(sum,kadaneMax);
            if(sum<0){
                sum=0;
            }
        }

        if(kadaneMax<0)return kadaneMax;
        // take dry run of [-2,-3,-5]  --> if (totalsum==excludedsum)-> min -> 0

        int kadaneMin=INT_MAX;
        int negsum=0;
         for(auto it:nums){
            negsum+=it;
            kadaneMin=min(negsum,kadaneMin);
            if(negsum>0){
                negsum=0;
            }
        }

        cout<<kadaneMin<<endl;

        return max(kadaneMax,totalsum-kadaneMin);



    }
};