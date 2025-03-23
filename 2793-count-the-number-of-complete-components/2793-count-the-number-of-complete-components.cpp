class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            adj[i].push_back(i);
        }

       // create adjacency list 
       for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
       }

    //    unordered_map<vector<int>,int>mpp;
       map<vector<int>,int>mpp;

       for(int i=0;i<n;i++){
          vector<int>temp=adj[i];
          sort(temp.begin(),temp.end());
          mpp[temp]++;
       }

       int count=0;

       for(auto it:mpp){
          if(it.first.size()==it.second){
            count++;
          }
       }

       return count;

    }
};