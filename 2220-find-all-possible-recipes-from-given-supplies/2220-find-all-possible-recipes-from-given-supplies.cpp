class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // gooing with the similar approach as was course schedule ii 
        unordered_map<string,int>indegree;
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                mpp[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }


        queue<string>q;
        for(auto it:supplies){
            q.push(it);
        }

        vector<string>ans;

        while(!q.empty()){
            string node=q.front();
            q.pop();

            for(auto it:mpp[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }

        return ans;
    }
};