class Solution {
    static bool compare(int a , int b){
        return abs(a)<abs(b);
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        for(int i=0;i<nums.size();i++){
            nums[i]=pow(nums[i],2);
        }
        
        return nums;
    }
};