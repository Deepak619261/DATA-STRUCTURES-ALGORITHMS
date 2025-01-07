class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {

         long long zero =0;
        sort(coins.begin(),coins.end());
        long long answer=0;
        int n=coins.size();
        int j=0;

        // the part where we are taking the possibilites where we are taking elements starting from the left li

        long long curr=0;
    
        for(int i=0;i<n;i++){
            while(j<n && coins[j][1]<=coins[i][0]+k-1){
                curr+=(long long)(coins[j][1]-coins[j][0]+1)*(long long)coins[j][2];
                j++;
            }
            if(j<n){
                long long part=max(zero,(long long)(coins[i][0]+k-1-coins[j][0]+1)*coins[j][2]);
                answer=max(answer,curr+part);
            }
            curr-=(long long)(coins[i][1]-coins[i][0]+1)*coins[i][2];
        }

        curr=0;

       // now for the part where we are taking k-bags and they are ending at the A[i][1]
    //    we will simply add the whole segment and then we will see that if there is any parital overlapping region we will subtract that segment 
    j=0;
    for(int i=0;i<n;i++){
        curr+=(long long)(coins[i][1]-coins[i][0]+1)*coins[i][2];
        while(coins[j][1]<coins[i][1]-k+1){
            curr-=(long long )(coins[j][1]-coins[j][0]+1)*coins[j][2];
            j++;
        }
       

        long long part=max(zero,(long long)(coins[i][1]-k+1-coins[j][0])*coins[j][2]);
        answer=max(answer,curr-part);

    }




        return answer;
    }
};