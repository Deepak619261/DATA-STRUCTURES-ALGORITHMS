class Solution {
    int MOD=1e9+7;

    long long power(long long base, long long exp){
        long long ans=1;
        base=base%MOD;

        while(exp){
            if(exp%2==1){
                ans=(ans*base)%MOD;
                exp=exp-1;
            }
            else{
                base=(base*base)%MOD;
                exp=exp/2;
            }
        }
        return ans;
    }
    int nCr(int first , int second){
        if (second < 0 || second > first || first < 0) return 0; 
        long long numer=1;

        for(int i=first;i>second;i--){
            numer=(long long)i*(long long)numer;
            numer=numer%MOD;
        }
        
        long long den=1;
        int lim=first-second;
        for(int i=lim;i>=1;i--){
            den=(long long)den*(long long)i;
            den=den%MOD;
        }

        long long res=(numer*power(den,MOD-2))%MOD;
        return (int)res;
    }
public:
    int countValidSequences(int n, int k) {
        //  we want sum of n and all integers product should be even , for all to be even , atleast one should be even ---> should ring -> complement thinking -> if we somehow find the sequences whosse product is only odd 
        int second=0;
        int bad=0;
        if(n-k>=0 && (n-k)%2==0){
        second=(n+k-2)/2;    
        bad=nCr(second,k-1);
        }
        // cout<<"total combinations are :- "<<nCr(n-1,k-1)<<endl;
        // cout<<"the rest are :- "<<nCr(second,k-1)<<endl;
        return ((nCr(n-1,k-1)-bad)%MOD+MOD)%MOD;
    }
};