class Solution {
    int parity(int num){
        // check all the 32 bits 
        if(num%2==0)return 1;
        else return 2;
    }
public:
    bool isArraySpecial(vector<int>& nums) {

        if(nums.size()==1)return true;

        for(int i=1;i<nums.size();i++){
            if(parity(nums[i])==parity(nums[i-1]))return false;
        }      

        return true;
    }
};