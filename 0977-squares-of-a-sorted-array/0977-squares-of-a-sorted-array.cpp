class Solution {
    static bool compare(int a , int b){
        return abs(a)<abs(b);
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // sort(nums.begin(),nums.end(),compare);
        // for(int i=0;i<nums.size();i++){
        //     nums[i]=pow(nums[i],2);
        // }
        
        // return nums;
        int left=0;
        int right =nums.size()-1;
        vector<int>temp(nums.size(),0);
        int k=temp.size()-1;
        while(left<=right && k>=0){
            if(pow(nums[left],2)>pow(nums[right],2)){
                temp[k--]=pow(nums[left++],2);
            }
            else{
                temp[k--]=pow(nums[right--],2);
            }

        }
        return temp;
    }
};