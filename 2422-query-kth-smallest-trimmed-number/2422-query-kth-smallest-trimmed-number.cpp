class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>answer;
        

        

        for(int i=0;i<queries.size();i++){
            int trim=queries[i][1];
            int kth=queries[i][0];
            int digitsize=nums[0].size();
            int ind=digitsize-trim;
            
            

            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>pq;
            for(int j=0;j<nums.size();j++){
                string number=nums[j].substr(ind);    
                pq.push({number,j});
            }

            for (int count = 1; count < kth; count++) {
                pq.pop();
            }
            answer.push_back(pq.top().second);

        }

        return answer;
    }
};