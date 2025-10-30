class Solution {

 int calculateones(int n){
        int count=0;
        while(n){
           if(n&1){
            count++;
           }
           n=n>>1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);

        for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+i%2;
        }

        return ans;

    }
};