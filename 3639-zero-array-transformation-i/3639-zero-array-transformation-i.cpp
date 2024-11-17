class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //  a very efficient algortihm -> sweep line algorithm 
        vector<int>arr(nums.size()+1,0);

        for(int i=0;i<queries.size();i++){
            arr[queries[i][0]]++;
            arr[queries[i][1]+1]--;
        }
        

        int val=0;
        for(int i=0;i<nums.size();i++){
            val=val+arr[i];

            //  we are comparing value all the values accumulated , if its not greator than given value then it can't make it zero never 
            if(val<nums[i]) return false;
        }

        return true;
    }
};