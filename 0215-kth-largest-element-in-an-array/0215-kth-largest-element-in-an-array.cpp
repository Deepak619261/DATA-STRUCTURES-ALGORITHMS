class Solution {
    int partitionIndex(vector<int>&nums, int left, int right){
          int pivot=nums[left];

          int r=right;
          int l=left+1;
          while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot){
                //  we have to oppose the order 
                swap(nums[l],nums[r]);
                r--;
                l++;
            }
            if(nums[l]>=pivot){
                l++;
            }
            if(nums[r]<=pivot){
                r--;
            }
          }
          swap(nums[left],nums[r]);
          return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index=k-1;
        int left=0;
        int right=nums.size()-1;
        while(left>=0 && right<=nums.size()){
            int idx=partitionIndex(nums,left,right);
            if(idx==index){
                int ans=nums[idx];
                return ans;
            }

            if(idx>index){
                right=idx-1;
            }
            else{
                left=idx+1;
            }
        }
        return -1;
    }
};