class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // kahn's algorithm 
        // reverse the edges 

        int V=graph.size();
        vector<vector<int>>adj(V);

        // reverse the edges so that safe node will be with the indegree zero 

        vector<int>indegree(V,0);

        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
        }

        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};