class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
         // code here
        unordered_map<int,int>mpp;

        mpp[0]=1;
        
        
        //  reverse engineering --> i have take sum till the ith index  , for k subarray need to 
        // to be exists i should have one sum-k before in this loop 
        
        int ans=0;
        long long sum=0;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];

            ans+=mpp[sum-k];


            mpp[sum]++;
            
        }
        
        return ans;
    }
};