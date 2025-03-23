class Solution {
    int mod=(int)(1e9+7);
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //  we'll store the number of ways to reach the destination also 
        vector<int>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);

        //  store the data into graph 
        vector<vector<pair<int,int>>>adj(n);

        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }


        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            long long distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            // if(node==n-1){
            //     continue;
            // }


            for(auto it:adj[node]){
                int wt=it.second;
                int adjNode=it.first;
                if(wt+distance<dist[adjNode]){
                    dist[adjNode]=wt+distance;
                    ways[adjNode]=ways[node];
                    pq.push({wt+distance,adjNode});
                }
                else if(wt+distance==dist[adjNode]){
                    ways[node]=ways[node]%mod;
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
            }
};