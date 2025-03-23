class Solution {
    void dfs(int node, vector<vector<int>>adj,vector<int>&visited,int &e, int &n){
        visited[node]=1;
        n++;
        e+=adj[node].size();
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,e,n);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // the whole bottleneck was to knowing that in a complete graph -> the number of edges are n*(n-1)/2 and 
        // and for every component we just needed to check these things 
        vector<vector<int>>adj(n);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }


        vector<int>visited(n,0);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int edgecount=0;
                int nodescount=0;
                dfs(i,adj,visited,edgecount,nodescount);
                if(edgecount==(nodescount*(nodescount-1)))ans++;
            }
        }
        return ans;
    }
};