class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        int ans=INT_MIN;

        for(auto it:mpp){
            if(it.first==it.second)ans=max(ans,it.first);
        }
         
        return (ans==INT_MIN)?-1:ans;
    }
};