class Solution {
    int MOD=1e9+7;
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int>temp(n,0);

        for(int i=0;i<n;i++){
            int it=nums[i];
            if(it<a){
                temp[i]=0;
            }
            else if(it>b){
                temp[i]=2;
            }
            else{
                temp[i]=1;
            }
        }

        int cnt0=0;
        int cnt1=0;
        int cnt2=0;

        int ans=0;

        for(auto it:temp){
            if(it==0){
                ans=(ans+(cnt1+cnt2))%MOD;
                cnt0++;
            }
            else if(it==1){
                ans=(ans+(cnt2))%MOD;
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        ans=ans%MOD;

        return ans;
    }
};