class Solution {
    int Height(int i,vector<int>& parent , vector<int>&ans){
         if(parent[i]==-1){
            return ans[i]=1;
         }

         if(ans[i]!=0)return ans[i];

         return ans[i]=Height(parent[i],parent,ans)+1;
       
    }
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        //  its the n-ary tree
        int n=parent.size();
        vector<int>ans(n,0);
        ans[0]=1; 

        // Height(parent,ans);
        int maxi=1;
        for(int i=1;i<n;i++){
            maxi=max(maxi,Height(i,parent,ans));
        }

        // for(int i=0;i<ans.size();i++){
        //     maxi=max(maxi,ans[i]);
        //     cout<<"for the node "<<i<<" the depth is : "<<ans[i]<<endl;
        // }

        long long answ=0;

        for(int i=0;i<nums.size();i++){
            answ+=(long long)(nums[i])*(maxi-ans[i]+1);
        }

        return answ;
    }
};