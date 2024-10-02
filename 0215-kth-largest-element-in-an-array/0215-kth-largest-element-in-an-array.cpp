class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int first=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(first;first<k;first++){
           pq.push(nums[first]);
        }

        for(first;first<nums.size();first++){
            pq.push(nums[first]);
            pq.pop();
        }

        return pq.top();
    }
};