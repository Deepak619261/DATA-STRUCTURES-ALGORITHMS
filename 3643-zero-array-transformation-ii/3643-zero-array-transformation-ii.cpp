class Solution {
    bool isAns(int mid,vector<int>&nums,vector<vector<int>>&queries){
        vector<int>diff(nums.size()+1,0);

        for(int i=0;i<mid;i++){
            diff[queries[i][0]]+=queries[i][2];
            diff[queries[i][1]+1]-=queries[i][2];
        }

        int op=0;

        for(int i=0;i<nums.size();i++){
            op+=diff[i];
            if(op<nums[i])return false;
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int s=0;
        int e=queries.size();
        int ans=INT_MAX;
        
        while(s<=e){
            int mid=(s+e)/2;
            if(isAns(mid,nums,queries)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        if(ans==INT_MAX)return -1;

        return ans;

    }
};