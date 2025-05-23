class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // have watched the editorial 
        
        // our objective is to find the minimum queries so that the array can become a zero array 
        //  if we carefully observe then we want that in queries the index i should come atlease nums[i] times only then that element can become zero , 
        // we will go greedily in this problem 
        sort(queries.begin(),queries.end());
        int n=nums.size();
        vector<int>diff(n+1,0);

        int j=0;
        int i=0;
        int op=0;

        priority_queue<int>pq;

        // diff array tracks the coverage 
        while(i<nums.size()){
             op+=diff[i];

             while(j<queries.size() && queries[j][0]==i){
                  pq.push(queries[j][1]);
                  j++;
             }

             while(op<nums[i] && !pq.empty() && pq.top()>=i){
                op+=1;
                diff[pq.top()+1]-=1;
                pq.pop();
             }

             if(op<nums[i])return -1;
             i++;
        }

        return pq.size();
    }
};