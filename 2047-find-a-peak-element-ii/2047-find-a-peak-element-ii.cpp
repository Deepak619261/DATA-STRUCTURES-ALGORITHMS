class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       // let's try the approach of finding the largest element 
       vector<int>ans;
       int row=-1;
       int col=-1;

       int maxi=INT_MIN;

       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(maxi<mat[i][j]){
                maxi=mat[i][j];
                row=i;
                col=j;
            }
        }
       }
       ans.push_back(row);
       ans.push_back(col);
       return ans;
    }
};