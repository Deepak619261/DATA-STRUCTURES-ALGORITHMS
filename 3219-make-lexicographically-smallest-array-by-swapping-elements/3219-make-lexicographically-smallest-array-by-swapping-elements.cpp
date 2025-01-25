class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        vector<int>original=nums;
        sort(nums.begin(),nums.end());

        map<int,int>mpp1;
        // mpp1 is to track the realtion of group number and current element 
        // mpp2 is to store the element to corresponding the group number
        map<int,queue<int>>mpp2;

        int currGroup=0;

        mpp1[nums[0]]=currGroup;
        mpp2[currGroup].push(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])>limit){
                currGroup++;
            }
            // currGroup++;
            mpp1[nums[i]]=currGroup;
            mpp2[currGroup].push(nums[i]);
        }

        for(int i=0;i<original.size();i++){
            int group=mpp1[original[i]];
            if(!mpp2[group].empty()){
                original[i]=mpp2[group].front();
                mpp2[group].pop();
            }
        }

        return original;
        
    }
};