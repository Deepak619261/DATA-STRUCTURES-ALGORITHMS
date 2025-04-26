class Solution {
    const int MOD=1e9+7;
    int power(long long x, long long y, int MOD) {
    int result = 1;
    x = x % MOD;  
    while (y > 0) {
        if (y % 2 == 1)  
            result = (result * x) % MOD;
        y = y >> 1;  
        x = (x * x) % MOD;  
    }
    return result;
}
    void dfs(vector<int>&ans,int node, vector<int>&visited,long long prod,vector<vector<pair<int,int>>>&adj){
            ans[node]=prod%MOD;
            visited[node]=1;
            for(auto it:adj[node]){
                if(!visited[it.first]){
                prod=(prod*it.second)%MOD;
                dfs(ans,it.first,visited,prod,adj);
                prod = (prod * power(it.second, MOD - 2, MOD)) % MOD;
                }
            }
            visited[node]=0;
    }
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n=conversions.size();
        vector<vector<pair<int,int>>>adj(n+1);
       
       // simple its a graph problem nothing else , don't overhype the contests , solve them 

        for(auto it:conversions){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>ans(n+1,0);
        ans[0]=1;
        
        vector<int>visited(n+1,0);
        dfs(ans,0,visited,1,adj);

        return ans;
    }
};