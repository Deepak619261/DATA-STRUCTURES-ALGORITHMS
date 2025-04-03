class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long answer=0;
        // maintain a maximum ele array for the nums[k]
        // same for the nums[i]
        int n=nums.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);

        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            leftMax[i]=maxi;
        }

        maxi=nums[n-1];

        for(int i=n-1;i>=0;i--){
            maxi=max(nums[i],maxi);
            rightMax[i]=maxi;
        }

        for(int i=1;i<n-1;i++){
            long long check=leftMax[i-1]-nums[i];
            check=check*rightMax[i+1];
            if(check>0){
                answer=max(answer,check);
            }
        }

        return answer;
    }
};