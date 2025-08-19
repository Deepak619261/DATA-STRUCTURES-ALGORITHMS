class Solution {
    void solve(int index,int count, vector<vector<int>>&ans,vector<int>temp,vector<int>&nums,int sum,int k,int n){
        
         if(count==k){
            cout<<sum<<endl;
            if(sum==n)ans.push_back(temp);
            return;
         }
         if(index==nums.size()){
            if(count==k){
            if(sum==n)ans.push_back(temp);
         }
         return;
         }

        //   on every index we have two choices either we pick the current index or we don't 
        //  first lets pick 
        temp.push_back(nums[index]);
        solve(index+1, count+1,ans,temp,nums,sum+nums[index],k,n);
        temp.pop_back();
        solve(index+1,count,ans,temp,nums,sum,k,n);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        solve(0,0,ans,temp,nums,0,k,n);
        return ans;

    }
};