class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        //  the main bottleneck of this problem is storing the produtct of remaining array 
        //  the very clear thing is we don't want to any product which is greator than in worst case -> 10^5x10^9 -> 1e14

        if(nums.size()==1)return -1;
        long long limit=1e14;
        vector<long long>prod(nums.size()+1,1);
        // long long mul=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(prod[i+1]>(limit/nums[i])){
                prod[i]=limit+1;
            }
            else{
                prod[i]=prod[i+1]*nums[i];
            }
        }

        long long leftsum=0;

        for(int i=0;i<nums.size();i++){
           if(leftsum==prod[i+1])return i;
           leftsum+=nums[i];
        }

        return -1;
        
    }
};