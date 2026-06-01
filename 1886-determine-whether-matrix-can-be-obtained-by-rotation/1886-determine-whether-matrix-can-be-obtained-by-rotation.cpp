class Solution {

     vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        // brute force will be storing in the given output and then overwrite the array 
        // keep the right diagonal same and take the mirro about that 

        // and then just take mirro on the middle row 

        // express the diagnol mirroring in terms or row and colum 
        // take the middle mirro in terms of row and coln 
        int n=matrix.size();
        int limit=ceil(n/2.0);
        for(int row=0;row<n;row++){
            for(int col=0;col<n-row-1;col++){
                swap(matrix[row][col],matrix[n-col-1][n-row-1]);
            }
        }

        // for(int row=0;row<n;row++){
        //     for(int col=0;col<n;col++){
        //         cout<<matrix[row][col]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int row=0;row<limit;row++){
            for(int col=0;col<n;col++){
                swap(matrix[row][col],matrix[n-row-1][col]);
            }
        }

        return matrix;

        // now we just need to mirro it around its middle line more   
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
     vector<vector<int>>matrix=mat;


     for(int i=0;i<4;i++){
     matrix=rotate(matrix);
     if(matrix==target)return true;
     }


     return false;


        



    }
};