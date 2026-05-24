class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //  take i from zero to k 
        // put the conditions 
        vector<int>evencost(k,0);
        vector<int>oddcost(k,0);

        // int temp=0;
        for(int r=0;r<k;r++){
            for(int i=0;i<nums.size();i++){
                int diff=abs((nums[i]%k)-r);
                diff=min(diff,k-diff);
                if(i%2==0){
                    evencost[r]+=diff;
                }
                else{
                     oddcost[r]+=diff;
                }
            }

        }

        int cnt=INT_MAX;
        for(int x=0;x<k;x++){
            for(int y=0;y<k;y++){
                if(x==y)continue;
                //  mentioned in problem statement 
               

                // for(int i=0;i<nums.size();i++){
                //     if(i%2==0){
                //         int diff=abs((nums[i]%k)-x);
                //         cost+=min(diff,k-diff);
                //     }
                //     else{
                //         int diff=abs((nums[i]%k)-y);
                //         cost+=min(diff,k-diff);
                //     }
                // }
                cnt=min(cnt,evencost[x]+oddcost[y]);
                // cnt+=something;
            }
        }

        return cnt;
    }
};