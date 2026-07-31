class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());

        int last=INT_MIN;
        int longest=1;
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==last){
                cnt++;
            }
            else if(nums[i]!=last){
                // prevents the duplicate check 
                cnt=1;
            }
            last=nums[i];
            longest =max(cnt,longest);

        }

        return longest;
    }
};