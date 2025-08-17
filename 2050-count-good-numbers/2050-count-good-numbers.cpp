class Solution {
    int MOD=1e9+7;
    long long mod_exp(long long x  , long long n){
        if(x==1)return 1;
        if(n==1)return x;
        if(n==0)return 1;
        
        //  there can be two case either n will be odd or even 
        long long ans=1;
        if(n%2==0){
            ans=(long long)ans*(long long)(mod_exp((long long)x*x%MOD,n/2));
            ans=ans%MOD;
        }
        else{
            ans=ans*x;
            ans=(long  long)ans*(long long)(mod_exp(x,n-1));
            ans=ans%MOD;
        }

        return ans%MOD;

    }
public:
    int countGoodNumbers(long long n) {
        //  see first mistake is not reading question carefully , the question says prime not , odd 
        // for every odd indices we have only 4 choices which are 1 ,3 , 5, 7 
        long long ans=1;
        

        long long evenindcnt=0;
        long long oddindcnt=n/2;


        evenindcnt=n-oddindcnt;

        return (mod_exp(4,oddindcnt)*mod_exp(5,evenindcnt))%MOD;  
    }
};