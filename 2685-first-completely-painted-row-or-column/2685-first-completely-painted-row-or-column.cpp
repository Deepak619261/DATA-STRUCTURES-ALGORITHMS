class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // able to find the apprach by seeing the two hints , the main hint that gave the intution was hint 2
        int m=mat.size();
        int n=mat[0].size();

        map<int,pair<int,int>>mpp;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mpp[mat[i][j]]={i,j};
            }
        }

        vector<int>rows(m,n);
        vector<int>cols(n,m);

        for(int i=0;i<arr.size();i++){
            int ele=arr[i];
            auto it=mpp[ele];
            rows[it.first]--;
            if(rows[it.first]==0)return i;

            cols[it.second]--;
            if(cols[it.second]==0){
                return i;
            }
        }
        return 0;
    }
};