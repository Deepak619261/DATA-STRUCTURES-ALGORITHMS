class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant=nums[0];
        int count=1;
        int n=nums.size();

        for(int i=1;i<nums.size();i++){
           if(nums[i]==dominant){
            count++;
           }
           else{
            count--;
            if(count==0){
                dominant=nums[i];
                count=1;
            }
           }
        }

        int totalDominantX=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==dominant){
                totalDominantX++;
            }
        }
        cout<<totalDominantX;

        int curr=0;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==dominant)curr++;

            if((curr>(i+1)/2) && (totalDominantX-curr)>(n-i-1)/2)return i;
        }

        return -1;


    }
};