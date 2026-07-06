class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;

        if(n<0){
            x=1.0/x;
        }

        long long lim=abs((long long)n);

        while(lim>0){
            if(lim%2==1){
                ans=ans*x;
                lim=lim-1;
            }
            else{
                x=(x*x);
                lim=lim/2;
            }
        }

        return ans;
    }
};