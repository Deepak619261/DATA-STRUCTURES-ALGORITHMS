class Solution {
public:
    int smallestRepunitDivByK(int k) {
        //  lets think -> k can range from 1 to 105
        // and n can be only 11111111 , the string consisting of one's only 
        //  so every remainder is in the range of the number from which we are dividing 
        unordered_set<int>st;
        long long n =1;
        int count=1;
        int remainder=n%k;
        st.insert(remainder);
        if(remainder==0)return 1;


        while(true){
            remainder = (remainder * 10 + 1) % k;
            count++;
            if(remainder==0){
                return count;
            }
            if(st.count(remainder)>0){
                return -1;
            }
            else{
                st.insert(remainder);
            }

        }
        return -1;
    }
};