class Solution {
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
        //  brute force will be the linear search 
        //  here is the better approach than brute force
        //  traverse every row and check if the element is in the range 
        int n=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<=matrix[i][n-1]){
                return binarySearch(matrix[i],target);
            }
        } 


        return false;
        // this will take O(N+logM)
    }
};