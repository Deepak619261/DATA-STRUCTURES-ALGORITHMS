class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        // lets go with the brute force first 
        set<vector<int>>st;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                   if((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff)){
                      vector<int>check={nums[i],nums[j],nums[k]};
                      if(st.count(check)==0){
                        count++;
                        st.insert(check);
                      }
                   }
                }
            }
        }
        return count;
    }
};