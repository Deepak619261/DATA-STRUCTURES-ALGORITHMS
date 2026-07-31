class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //  lets go with the brute force first 

        //  intiliaze a count , and pick a element and count if its next element exists while it exists increment the count and keep taking the maxi 
        int ans=0;
        int count=1;

        unordered_map<int,int>mpp;

        for(auto it:nums){
            mpp[it]++;
        }


        for(auto it:mpp){
            if(!mpp.contains(it.first-1)){
            count=1;
            int num=it.first;
            while(mpp.contains(num+1)){
                count++;
                num++;
            }
            }
            ans=max(ans,count);
        }

        return ans;


    }
};