class Solution {
    void solve(int index, vector<vector<int>>&ans,vector<int>temp,int sum , int k , int n ){
        if(temp.size()==k){
            if(sum==n)ans.push_back(temp);
            return;
        }

        //  loop from the index to  9 

        for(int i=index;i<10;i++){
            if(sum+i>n)break;
            temp.push_back(i);
            solve(i+1,ans,temp,sum+i,k,n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,ans,temp,0,k,n);
        return ans;
    }
};