class Solution {
bool istriangle(int a, int b, int c){
    
if(a+b>c && a+c>b && c+b>a){return true;}

return false;

}
public:
    string triangleType(vector<int>& nums) {

        if(!istriangle(nums[0],nums[1],nums[2]))return "none";
        if(nums[0]==nums[1] && nums[1]==nums[2])return "equilateral";

if(nums[0]==nums[1] || nums[1]==nums[2] || nums[2]==nums[0]) return "isosceles";


return "scalene";





    }
};