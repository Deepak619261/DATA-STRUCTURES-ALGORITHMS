class Solution {
    int MOD=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // dijkstra algorithm 
        priority_queue< pair<long long,int> , vector<pair<long long,int>>,greater<pair<long,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);

        dist[0]=0;

        vector<vector<pair<int,int>>>adj(n);

        // node -> {adj node , weight}

        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        dist[0]=0;
        pq.push({0,0});
        vector<long long>ways(n,0);
        ways[0]=1;
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            long long wt=it.first;
            pq.pop();

            for(auto it:adj[node]){
                int adjnode=it.first;
                if(wt+it.second<dist[adjnode]){
                    dist[adjnode]=wt+it.second;
                    ways[adjnode]=ways[node]%MOD;
                    pq.push({wt+it.second,adjnode});
                }
                else if(wt+it.second==dist[adjnode]){
                    ways[adjnode]+=ways[node]%MOD;
                }
            }
        }
        return ways[n-1]%MOD;

        

        
    }
};