class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        // the approach is very basic , we just nned to sort the given array and pick the element and compare with the very first ,element if its validating the criteria then after that all the elements will be requring the criteira already because the max diff can be achieved fromthe first ele itself 
        int i=0;
        sort(nums.begin(),nums.end());
        while(i<nums.size()){
            vector<int>temp;
            int ref=nums[i];
            temp.push_back(ref);
            int j=i+1;
            if(nums[j]-ref<=k && ref-nums[j]<=k && nums[j+1]-ref<=k && ref-nums[j+1]<=k){
               temp.push_back(nums[j]);
               temp.push_back(nums[j+1]);
            }
            else{
                return {};
            }
            ans.push_back(temp);
            i=j+2;
        }

        return ans;
    }
};