class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //  optimized one 
        bool isfirstrowzero=false;
        bool isfirstcolzero=false;
        

        //  handle the first row and col seprately 
        int m=matrix.size();
        int n =matrix[0].size();

        for(int j=0;j<n;j++){
            if(matrix[0][j]==0)isfirstrowzero=true;
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)isfirstcolzero=true;
        }

        //  take the remainng grid 

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(isfirstrowzero){
             for(int j=0;j<n;j++){
            matrix[0][j]=0;
        }

        }

        if(isfirstcolzero){
            for(int i=0;i<m;i++){
           matrix[i][0]=0;
        }

        }

        

    }
};