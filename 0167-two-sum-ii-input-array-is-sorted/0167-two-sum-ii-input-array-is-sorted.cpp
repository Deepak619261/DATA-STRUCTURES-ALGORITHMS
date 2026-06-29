class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // this is the classic pattern -> put the start and end , decrease on that side whose criteria is not matching 

        int start=0;
        int end=numbers.size()-1;

        while(start<end){
          int sum=numbers[start]+numbers[end];
          if(sum==target)return {start+1,end+1};

          if(sum>target){
            end--;
          }
          else{
            start++;
          }
        }
        return {start,end};
    }
};