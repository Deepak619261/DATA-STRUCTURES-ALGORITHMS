class Solution {
    void solve(vector<vector<int>>&res ,vector<int>temp,int n ,vector<bool>freq,vector<int>nums){
      if(temp.size()==n)res.push_back(temp);

    //    put a for loop 
    for(int i=0;i<n;i++){
        if(!freq[i]){
            temp.push_back(nums[i]);
            freq[i]=true;
            solve(res,temp,n,freq,nums);
            freq[i]=false;
            temp.pop_back();
        }
    }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //  lets go with the recursive approach 
        int n=nums.size();
        vector<bool>freq(n,false);
        vector<vector<int>>res;
        vector<int>temp;
        solve(res,temp,n,freq,nums);
        return res;
    }
};