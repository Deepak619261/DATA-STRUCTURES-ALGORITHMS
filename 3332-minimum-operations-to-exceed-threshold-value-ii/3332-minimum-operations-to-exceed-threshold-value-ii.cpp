class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //  so the approach is using priority queue , we just have to repeat the process till we don't find element greater than or equal to k 
        // in constraints its given that there will always answer will exist 
        priority_queue <long long, vector<long long>, greater<long long>> pq;
        int count=0;

        for(auto it:nums)pq.push(it);

        while(pq.top()<k){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();

            long long put=(long long)(min(x,y)*2+max(x,y));

            pq.push(put);
            count++;
        }

        return count;
    }
};