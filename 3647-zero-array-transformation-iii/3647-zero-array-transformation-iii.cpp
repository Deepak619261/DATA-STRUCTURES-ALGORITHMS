class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // upsolving the question from the virtual contest on the leetcode biweekly 144
        priority_queue<int>pick; // normal queue acts as max heap means it will have the greatest element on the top of the queue 
        priority_queue<int,vector<int>,greater<int>>used;  // mean heap will contain the minimum element on its top 

        //  sort the queries so we can get the index wise queries as we want the minimum query to get used 

        sort(queries.begin(),queries.end());
        int j=0;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            while(j<queries.size() && queries[j][0]==i){
                pick.push(queries[j][1]);
                j++;
            }

            //  check if we can subtract the current element with already used queries 
            nums[i]-=used.size();

            while(nums[i]>0 && !pick.empty() && pick.top()>=i){
                ans++;
                used.push(pick.top());
                pick.pop();
                nums[i]--;
            }

            //  still we are not able to make the element zero 
            if(nums[i]>0)return -1;

            while(!used.empty() && used.top()==i)used.pop();
        }

        return queries.size()-ans;
    }
};