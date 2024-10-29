class Solution {
    int reverse(int x) {
        int num=abs(x);

        int ans=0;

        while(num){
            int digit=num%10;
            if(x>0 && ans>(INT_MAX/10)) return 0;
            if(x<0 && -ans<(INT_MIN/10)) return 0;
            ans=ans*10+digit;

            num=num/10;
        }

        if(x<0) return -ans;

        return ans;
    }
public:
    bool isPalindrome(int x) {

        if(x<0) return false;
        
        return x==reverse(x);
        

    }
};