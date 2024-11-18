class Solution {

    bool isvalid(int k,vector<vector<int>>& queries,vector<int>nums){
        vector<int>arr(nums.size()+1);

        for(int i=0;i<k;i++){
            arr[queries[i][0]]+=queries[i][2];
            arr[queries[i][1]+1]-=queries[i][2];
        }

        int op=0;
        for(int i=0;i<arr.size()-1;i++){
            op=op+arr[i];
            arr[i]=op;
            if(arr[i]<nums[i])return false;
        }

        return true;

    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //  going with approach given in soutions 
        int low=0;
        int high=queries.size()+1;
        int ans=-1;

        while(low<high){
             int mid=low+(high-low)/2;
             if(isvalid(mid,queries,nums)){
                ans=mid;
                high=mid;
             }
             else{
                low=mid+1;
             }
        }

        if(ans<=queries.size()){
            return ans;
        }

        return -1;
    }
};