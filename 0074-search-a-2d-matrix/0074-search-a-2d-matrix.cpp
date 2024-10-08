class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //  this question can be solved simply by formula 
        // seach space will be 0 to row*col-1
        int low=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int high=m*n-1;


        while(low<=high){
            int mid=low+(high-low)/2;
            int row=(mid/n);
            int col=mid%n;
            if(target==matrix[row][col]) return true;

            if(target>matrix[row][col]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return false;
    }
};