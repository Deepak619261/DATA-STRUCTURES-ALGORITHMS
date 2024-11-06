int mod=1e9+7;
class Solution {
    long long  modular_exp(long long x, long long y){
        // x^y
        if(y==0){
            return 1;
        }
        if(y==1){
            return x;
        }

        long long ans=modular_exp(x,y/2);
        ans=ans%mod;
        ans*=ans;
        ans=ans%mod;

        if(y%2){
            ans=ans*x;
            ans=ans%mod;
        }
        return ans;
        
    }
public:
    int countGoodNumbers(long long n) {
        //  so the optimized approach is here
        

        long long ans=1;
        

        long long evenindcnt=0;
        long long oddindcnt=n/2;


        evenindcnt=n-oddindcnt;
        
        ans*=modular_exp(4,oddindcnt);
        ans=ans%mod;

        ans*=modular_exp(5,evenindcnt);
        ans=ans%mod;
              
        // in any number there will be half even indexes and half odd index 
        return ans;
    }
};