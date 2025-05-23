class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>Rarr(m,0);
        vector<int>Carr(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    Rarr[i]=1;
                    Carr[j]=1;
                }
            }
        }

        for(int i=0;i<Rarr.size();i++){
            if(Rarr[i]==1){
                for(int k=0;k<matrix[i].size();k++){
                    matrix[i][k]=0;
                }
            }
        }

        for(int i=0;i<Carr.size();i++){
            if(Carr[i]==1){
                for(int k=0;k<matrix.size();k++){
                    matrix[k][i]=0;
                }
            }
        }
    }
};