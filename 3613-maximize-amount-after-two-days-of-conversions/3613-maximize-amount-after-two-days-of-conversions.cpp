class Solution {
    void store(unordered_map<string,vector<pair<string,double>>>&adj1,vector<pair<string,double>>&res,double ans,string curr,string parent){
        res.push_back({curr,ans});

        for(auto it:adj1[curr]){
            if(it.first==parent)continue;
            store(adj1,res,ans*it.second,it.first,curr);
        }
        
    }

    double solve(string curr,string parent,unordered_map<string,vector<pair<string,double>>>&adj2,string target){
            if(curr==target){
                return 1.0;
            }

            double ans=0.0;

            for(auto it:adj2[curr]){
                if(it.first==parent)continue;
                double val=it.second*solve(it.first,curr,adj2,target);
                ans=max(ans,val);
            }

            return ans;

    }
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        //  make a graph of pairs1 
        
        unordered_map<string,vector<pair<string,double>>>adj1;
        unordered_map<string,vector<pair<string,double>>>adj2;
        

        for(int i=0;i<pairs1.size();i++){
            adj1[pairs1[i][0]].push_back({pairs1[i][1],rates1[i]});
            adj1[pairs1[i][1]].push_back({pairs1[i][0],1/rates1[i]});
        }

        vector<pair<string,double>>res;
        //  store the intermediate currencies 
        store(adj1,res,1.0,initialCurrency,"");


        //  take each node and start traversing in the second graph and try to get to the intitalcurrency and update the answers 
        
        for(int i=0;i<pairs2.size();i++){
            adj2[pairs2[i][0]].push_back({pairs2[i][1],rates2[i]});
            adj2[pairs2[i][1]].push_back({pairs2[i][0],1/rates2[i]});
        }

        // for(auto it : res){
        //     cout<<it.first<<","<<it.second<<endl;
        // }
       
        double ans=1.0;
        double temp=1.0;
        if(adj2.find(initialCurrency)==adj2.end())return 1.0;
        
        for(auto it :res){
            temp=it.second*solve(it.first,"",adj2,initialCurrency);
            ans=max(temp,ans);
        }


        return ans;
         
    }
};