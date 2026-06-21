class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        //  build the adjacency list how i dk
        vector<vector<int>>adj(n);


        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }

        vector<long long>effectivetime;

        for(auto it:baseTime){
            effectivetime.push_back(it);
        }
        


        for(int i=n-1;i>=0;i--){
            if(adj[i].size()==0){
                effectivetime[i]=baseTime[i];
            }
            else{
                //  take the maximum of its children 
                long long maxi=LLONG_MIN;
                long long mini=LLONG_MAX;
                for(auto it:adj[i]){
                    maxi=max(effectivetime[it],maxi);
                    mini=min(effectivetime[it],mini);
                }
                effectivetime[i]=(maxi-mini);
                effectivetime[i]+=(baseTime[i]+maxi);
            }
            // cout<<"for node "<<i<<" effectivetime is"<<effectivetime[i]<<endl;
            // cout<<" the value for maxi is "<<maxi<<" and value of mini is "<<mini<<endl;
        }

        return effectivetime[0];
        
    }
};