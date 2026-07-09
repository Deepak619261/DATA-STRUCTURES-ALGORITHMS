class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;

        int ele1=-1;
        int ele2=-1;


        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1++;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1 ){
                cnt2++;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;
        cnt2=0;

        int limit=n/3;

        for(auto it:nums){
            if(it==ele1){
                cnt1++;
            }
            else if(it==ele2){
                cnt2++;
            }
        }

        vector<int>res;

        if(cnt1>limit)res.push_back(ele1);

        if(cnt2>limit)res.push_back(ele2);

        return res;
    }
};