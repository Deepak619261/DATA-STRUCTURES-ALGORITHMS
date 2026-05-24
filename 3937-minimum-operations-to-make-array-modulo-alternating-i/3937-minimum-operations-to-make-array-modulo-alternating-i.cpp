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

        int e1=INT_MAX;
        int ei1=-1;
        int e2=INT_MAX;

        for(int r=0;r<k;r++){
            if(evencost[r]<e1){
                e2=e1;
                e1=evencost[r];
                ei1=r;
            }
            else if(evencost[r]<e2){
                e2=evencost[r];
            }
        }


        int o1=INT_MAX;
        int oi1=-1;
        int o2=INT_MAX;

        for(int r=0;r<k;r++){
            if(oddcost[r]<o1){
                o2=o1;
                o1=oddcost[r];
                oi1=r;
            }
            else if(oddcost[r]<o2){
                o2=oddcost[r];
            }
        }

        // int cnt=INT_MAX;
        // for(int x=0;x<k;x++){
        //     for(int y=0;y<k;y++){
        //         if(x==y)continue;
        //         //  mentioned in problem statement 
               

        //         // for(int i=0;i<nums.size();i++){
        //         //     if(i%2==0){
        //         //         int diff=abs((nums[i]%k)-x);
        //         //         cost+=min(diff,k-diff);
        //         //     }
        //         //     else{
        //         //         int diff=abs((nums[i]%k)-y);
        //         //         cost+=min(diff,k-diff);
        //         //     }
        //         // }
        //         cnt=min(cnt,evencost[x]+oddcost[y]);
        //         // cnt+=something;
        //     }
        // }

        // time complexity -> O(n*k)+O(k^2)
        if(ei1!=oi1)return e1+o1;


         return min(e1+o2,e2+o1);
        // return cnt;
    }
};