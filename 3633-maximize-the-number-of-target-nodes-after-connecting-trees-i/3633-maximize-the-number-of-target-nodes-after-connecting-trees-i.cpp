class Solution {
    int getcountBFS(vector<vector<int>>adj,int k,int node,int n){
        int count=0;
        queue<pair<int,int>>q;


        vector<int>vis(n,0);

        vis[node]=1;

        q.push({node,0});

        while(!q.empty()){
            auto it=q.front();
            int curr_node=it.first;
            int cnt=it.second;
            if(cnt<=k){
                count++;
            }
            q.pop();
            
            for(auto it : adj[curr_node]){
                if(!vis[it] && cnt+1<=k){
                    vis[it]=1;
                    q.push({it,cnt+1});
                }
            }
        }
    


        return count;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<int>ans(n,0);
        vector<int>store(m,0);
        int maxi=0;

        //  create adjacency list to get the count of node at distance k and k-1 and do the bfs to get count 
        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(m);

        for(auto it: edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }


        
        for(auto it: edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }






        //  step -1 get the count of all nodes which are at atmost k distance from current distance 
        for(int i=0;i<n;i++){
            ans[i]=getcountBFS(adj1,k,i,n);
        }

        // step -2 get the node value with maximum nodes connected at k-1 distance store it value 
        for(int i=0;i<m;i++){
            store[i]=getcountBFS(adj2,k-1,i,m);
            maxi=max(maxi,store[i]);
        }
        //  add the max value to all of the array and return the answer
        
        for(int i=0;i<ans.size();i++){
            ans[i]=ans[i]+maxi;
        }

        return ans;
    }
};