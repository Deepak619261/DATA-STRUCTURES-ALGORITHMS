class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //  take i from zero to k 
        // put the conditions 

        int cnt=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y)continue;
                //  mentioned in problem statement 
                int cost=0;

                for(int i=0;i<nums.size();i++){
                    if(i%2==0){
                        int diff=abs((nums[i]%k)-x);
                        cost+=min(diff,k-diff);
                    }
                    else{
                        int diff=abs((nums[i]%k)-y);
                        cost+=min(diff,k-diff);
                    }
                }
                cnt=min(cost,cnt);
                // cnt+=something;
            }
        }

        return cnt;
    }
};