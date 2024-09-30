class Solution {
    private:
     bool binarySearch(vector<int>nums,int target){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                if(binarySearch(matrix[i],target)) return true;
            }
        }
        return false;
    }
};