class Solution {
    vector<int> getPeakCol(vector<int>nums){
        vector<int>ans;
        int low=1;
        int n=nums.size()-1;
        int high=n-1;

        if(nums.size()==1){
            ans.push_back(0);
            return ans;
        }

        if(nums.size()==2){
            if(nums[0]>nums[1]){
                ans.push_back(0);
                return ans;
            }
            else{
                ans.push_back(1);
                return ans;
            }
        }

        

        if(nums[0]>nums[1]){
            ans.push_back(0);
        }
        if(nums[n]>nums[n-1]){
            ans.push_back(n);
        }
                
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            ans.push_back(i);
        }
    }
        return ans;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //  traverse through the each row and check for the element 

        int m=mat.size();
        if(m==1 && mat[0].size()==1){
            return {0,0};
        }
        vector<int>ans;
        
        

        for(int i=0;i<m;i++){
            vector<int>peaks=getPeakCol(mat[i]);
            

            for(int j:peaks){

            if(m==1){
                return {0,j};
            }

            int ele=mat[i][j];

            if(i==0){
                if(i+1<m && ele>mat[i+1][j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
            else if(i==m-1){
                if(i-1>=0 && ele>mat[i-1][j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
            else{
                if(ele>mat[i+1][j] && ele>mat[i-1][j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
                
            }
        }

        return ans;


    }
};