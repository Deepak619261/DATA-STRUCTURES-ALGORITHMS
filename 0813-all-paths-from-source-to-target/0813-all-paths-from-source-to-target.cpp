class Solution {
    // lets try the old school way 
    void solve(int node,vector<int>temp,vector<vector<int>>&graph,int n,vector<vector<int>>&ans){
        if(node==n-1){
           ans.push_back(temp);
           return;
        }

        for(auto it:graph[node]){
            temp.push_back(it);
            solve(it,temp,graph,n,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<int>temp;
        temp.push_back(0);
        solve(0,temp,graph,n,ans);
        return ans;
    }
};