class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // another approach can be -> maintain the maximums for all the indices in that way we just need to do this in O(n^2)
        int n=nums.size();
        vector<int>preMax(n,0);

        int maxi=nums.back();

        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            preMax[i]=maxi; 
        }

        for(auto it:preMax){
            cout<<it<<" ";
        }

        long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                long check=((long)nums[i]-(long)nums[j]);
                check=check*preMax[j+1];
                if(check>0){
                    ans=max(check,ans);
                }
            }
        }

        return ans;

        

        
        
    }
};