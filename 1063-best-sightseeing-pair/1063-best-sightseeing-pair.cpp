class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //  so we have to think in the way like this 
        //  we want to compute the value values[i]+values[j]-(j-i)
        //  rearrange the terms like (values[i]+i) + (values[j]-j) then think that we just want the maximum value of both terms , and first term we don't need to take care because with every index its values can be calculated , but we want for every index the maximum possible value of the second term and for that we will use a array 
        int maxi=INT_MIN;

        int n=values.size();
        vector<int>store(n);

        for(int i=n-1;i>=0;i--){
            if(values[i]-i>=maxi){
               maxi=values[i]-i;
            }
            store[i]=maxi;
        }

        for(auto it:store) cout<<it<<" ";

        int ans=INT_MIN;

        for(int i=0;i<n-1;i++){
            ans=max(ans,values[i]+i+store[i+1]);
        }

        return ans;
    }
};