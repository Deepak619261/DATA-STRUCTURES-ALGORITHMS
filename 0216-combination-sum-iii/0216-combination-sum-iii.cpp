class Solution {
    void solve(int index,int k, int n, vector<vector<int>>&ans,vector<int>store){
        if(index==k+1){
            if(n==0){
                ans.push_back(store);
            }
            return;
        }


        for(int i=index;i<=9;i++){
            if(!store.empty() && i<=store.back()) continue;

            store.push_back(i);
            n-=i;
            solve(index+1,k,n,ans,store);
            n+=i;
            store.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>store;
        solve(1,k,n,ans,store);

        return ans;
    }
};