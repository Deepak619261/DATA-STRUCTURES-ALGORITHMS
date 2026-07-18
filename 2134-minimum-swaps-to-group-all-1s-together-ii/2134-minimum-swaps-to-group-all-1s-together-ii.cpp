class Solution {
public:
    int minSwaps(vector<int>& nums) {
    vector<int>temp=nums;
    for(auto it:nums){
        temp.push_back(it);
    }
    int n = temp.size();
    int k = count(nums.begin(), nums.end(), 1);
    if (k == 0 || k == n) return 0;
    
    int zeros = 0;
    for (int i = 0; i < k; i++) if (temp[i] == 0) zeros++;
    
    int minZeros = zeros;
    for (int i = k; i < n; i++) {
        if (temp[i] == 0) zeros++;        // new element enters window
        if (temp[i-k] == 0) zeros--;      // old element leaves window
        minZeros = min(minZeros, zeros);
    }
    return minZeros;
    }
};