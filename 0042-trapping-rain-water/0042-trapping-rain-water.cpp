class Solution {
    vector<int>prefix(vector<int>height){
        int n=height.size();
        vector<int>ans(n);

        ans[0]=height[0];

        for(int i=1;i<n;i++){
            ans[i]=max(ans[i-1],height[i]);
        }

        return ans;
    }

    vector<int>suffix(vector<int>nums){
        int n=nums.size();

        vector<int>ans(n);
        ans[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i+1],nums[i]);
        }

        return ans;
    }
public:
    int trap(vector<int>& height) {
        //  better solution is precomputing the max element for the right side of the index 
        //  and for left side of the index including that index too 

        int ans=0;
        vector<int>next=suffix(height);
        vector<int>prev=prefix(height);

        for(int i=0;i<height.size();i++){
            ans+=min(next[i],prev[i])-height[i];
        }

        return ans;
    }
};