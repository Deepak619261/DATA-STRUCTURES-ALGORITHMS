class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // i don't know if i am founding these questions easy or am i understanding it wrong 

        int n=nums.size();
        //  first store the sum in from the right side of the array 
        vector<long long>temp(n,0);

        long long  curr=0;
        for(int i=n-1;i>=0;i--){
            curr+=nums[i];
            temp[i]=curr;
        }

        // expected output should be 13,3,-1,7

        curr=0;

        int ans=0;

        for(int i=0;i<n-1;i++){
           curr+=nums[i];
           if(curr>=temp[i+1])ans++;
        }



        return ans;
    }
};