class Solution {
public:
    string getPermutation(int n, int k) {
        vector<long long >fact(n+1,1);

        // precompute the factoiral 
        long long prod=1;
        for(int i=1;i<=n;i++){
           fact[i]=prod;
           prod=prod*(i+1);
        }

        // intution is think via fixing one digit , how many permutations are possible 

        k=k-1;
        // indexed with 0 indexing 
        vector<int>digits={1,2,3,4,5,6,7,8,9};
        string res="";

        for(int i=n;i>=1;i--){
            int blocksize=fact[i-1];
            int index=k/blocksize;
            res+=to_string(digits[index]);
            digits.erase(digits.begin()+index);
            k=k%blocksize;
        }

        return res;

    }
};