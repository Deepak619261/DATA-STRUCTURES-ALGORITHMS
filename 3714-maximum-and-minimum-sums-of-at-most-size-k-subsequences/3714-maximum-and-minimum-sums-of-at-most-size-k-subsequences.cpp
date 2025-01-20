class Solution {
    int MOD=1e9+7;

    long long powerexp(long long  x, long long n){
        long long ans=1;

        while(n>0){
            if(n%2==1){
                ans=(long long)(ans*x)%MOD;
                n=n-1;
            }
            else{
                x=(x*x)%MOD;
                n=n/2;
            }
        }

        return ans%MOD;
    }

    void precomputefact(vector<long long>&fact, vector<long long >&invfact,int n){
        fact.resize(n+1);
        invfact.resize(n+1);

        fact[0]=1;
        invfact[0]=1;

        for(int i=1;i<=n;i++){
            fact[i]=(fact[i-1]*i)%MOD;
        }

        invfact[n]=powerexp(fact[n],MOD-2);

        for(int i=n-1;i>=1;i--){
            invfact[i]=(invfact[i+1]*(i+1))%MOD;
        }
    }

    long long getnCr(int n, int r,vector<long long>&fact, vector<long long >&invfact){
        if(r>n || r<0)return 0;
        long long nfact=fact[n]%MOD;
        long long den=(invfact[r]*invfact[n-r])%MOD;
        long long res=(nfact*den)%MOD;
        return res;
    }
    
public:
    int minMaxSums(vector<int>& nums, int k) {
        //  watched approach from Youtube 
        // first we have to sort the array , because we just have bussiness with taking minimum and maximum element of a particular subsequence , subsequence means we can skip any element and pick some , so  [2,3,1] -> [1,2,3] ---> max and min are both same in both arrays
        //  sort it 

        // instead getting factorial inside the loop store it in a array for getting in O(1)

        // we have to do that first we have to iterate over every index and check in how may subsequences that element serves as minimum element and in how many as maximum element and just multiply with that element those number of subsequences to get our answers 

        //  lets say [1,2,3,4,5,6] we are at i=2 then the subsequences 
        //  for i=2 element as min element then one place is taken as we declared this element as min element and rest places are k-1 and the places to chosse are || right side of the index so (n-i-1) C (k-1) -> P&C formula -> number of ways of choosing k-1 element out of n-i-1 then multiply that value with current element 
        // for i=2 element as max element we have to consider the subsequences which are finishing at i=2 so again in that example we have to choose from i C(k-1) 
        // for every element we have to do the same and done !
      
       int n=nums.size();
       vector<long long>fact, invfact;

       sort(nums.begin(),nums.end());

       precomputefact(fact,invfact,n);

       long long answer=0;


       for(int i=0;i<nums.size();i++){
        for(int size=1;size<=k;size++){
            long long maxicount=(long long)(getnCr(n-i-1,size-1,fact,invfact)*nums[i])%MOD;
            long long minicount=(long long)(getnCr(i,size-1,fact,invfact)*nums[i])%MOD;

            answer=(answer+maxicount+minicount)%MOD;
        }
       }


       return answer;


    }
};