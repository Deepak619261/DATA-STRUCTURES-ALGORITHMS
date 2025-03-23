class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // just dijkstra but with max heap 
        vector<vector<pair<int,double>>>adj(n);
        priority_queue<pair<double,int>>pq;

        // build the adjacency list 

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

       for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (auto it : adj[i]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }

        vector<double>prob(n,INT_MIN);
        prob[start_node]=1;

        pq.push({1,start_node});

        while(!pq.empty()){
            auto it1=pq.top();
            pq.pop();
            int node=it1.second;
            double p=it1.first;

            for(auto it:adj[node]){
                int adjnode=it.first;
                double currp=it.second;
                // cout<<adjnode<<endl;
                // cout<<currp<<endl;
                if((p*currp)>prob[adjnode]){
                    prob[adjnode]=p*currp;
                    pq.push({prob[adjnode],adjnode});
                }
            }
        }


        if(prob[end_node]==INT_MIN)return 0;

        return prob[end_node];

        
    }
};