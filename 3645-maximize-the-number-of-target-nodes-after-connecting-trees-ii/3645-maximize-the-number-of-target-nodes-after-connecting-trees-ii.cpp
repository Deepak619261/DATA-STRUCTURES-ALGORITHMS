class Solution {
    int dfs(vector<vector<int>>&adj,vector<int>&parity,int node, int parent,int iseven){
        parity[node]=iseven;
        int count=0;
        if(iseven==0){
            count=1;
        }

        for(auto it:adj[node]){
            if(it!=parent){
                count+=dfs(adj,parity,it,node,!iseven);
            }
        }
        return count;
    }
    
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<int>ans(n,0);
        // int maxi=0;

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

        

        //  make a parity array for checking if the curernt node in the first node is even or odd 

        // vector<int>ans(n,0);
        vector<int>parity(n,-1);
        vector<int>dummy(m,-1);
        int firsteven=dfs(adj1,parity,0,-1,0);
        int firstodd=n-firsteven;

        int secondeven=dfs(adj2,dummy,0,-1,0);
        int maxi=max(secondeven,m-secondeven);


        for(int i=0;i<parity.size();i++){
            if(parity[i]==0){
                ans[i]=firsteven+maxi;
            }
            else{
                ans[i]=firstodd+maxi;
            }
        }



        return ans;

    




    
    }
};