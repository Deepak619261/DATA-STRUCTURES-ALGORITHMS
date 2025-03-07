class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // apply the sieve of eratosthene for checking the isprime in O(1)
        int n =1e6;
        vector<int>isPrime(n+1,1);
        // a prime number is that number that has two factors only , 1 and itself and greator than 1 
        isPrime[0]=isPrime[1]=0;


        for(int i=2;i<=sqrt(n);i++){
            // if the current index is prime 
            if(isPrime[i]==1){
                //mark all its multiple as non prime 
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=0;
                }
            }
        }
        // start a loop from right to left , and there should exist a variable named diff as INTMAXX, and there should be two variable two , just store the their difference , there would be no two duplicate as we are storing the two primme numbers 
        int diff=INT_MAX;
        int num2=INT_MAX;
        int num1=INT_MAX;

        int a1=0;
        int a2=0;

        for(int i=right;i>=left;i--){
            if(isPrime[i]){
                num2=num1;
                num1=i;
            }
            if(num1!=INT_MAX && num2!=INT_MAX){
                // there may be two conditions ,either equals the diff or greator
                if(diff>(num2-num1)){
                    a2=num2;
                    a1=num1;
                }
                else if(diff==(num2-num1)){
                    if(num1<a1){
                        a1=num1;
                        a2=num2;
                    }
                }
                diff=min(diff,(num2-num1));
            }
        }
        // if at the end of the iteration we found our difference as INT_MAX then we ahave to return [-1,-1]
        if(diff==INT_MAX){
            return {-1,-1};
        }

        return {a1,a2};
    }
};