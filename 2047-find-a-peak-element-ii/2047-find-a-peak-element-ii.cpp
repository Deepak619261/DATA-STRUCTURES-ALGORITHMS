class Solution {
    int getmaxrow(vector<vector<int>>& mat, int col, int m){
        int ans=-1;
        int maxi=INT_MIN;

        for(int i=0;i<m;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                ans=i;
            }
        }

        return ans;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=mat[0].size()-1;

        while(low<=high){
            int mid=(low+high)/2;
            int i=getmaxrow(mat,mid,m);

            int left=-1;
            int right=-1;

            int ele=mat[i][mid];

            if(mid+1<n) right=mat[i][mid+1];
            if(mid-1>=0) left=mat[i][mid-1];

            if(ele>left && ele>right){
                return {i,mid};
            }
            else if(left>ele){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return {-1,-1};
    }
};