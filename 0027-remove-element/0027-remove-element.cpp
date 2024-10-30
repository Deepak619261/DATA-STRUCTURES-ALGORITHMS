class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        vector<int>store;
        
        for(auto it:nums){
            if(it!=val){
                ans++;
                store.push_back(it);
            }
        }



        for(int i=0;i<store.size();i++){
            nums[i]=store[i];
        }

        

           
        return ans;
    }
};