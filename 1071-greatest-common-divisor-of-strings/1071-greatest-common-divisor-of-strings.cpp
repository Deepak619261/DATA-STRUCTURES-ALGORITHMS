class Solution {
    int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }
        if(a==0)return b;
        return a;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1+str2)!=(str2+str1))return "";

        int n1=str1.size();
        int n2=str2.size();
        int len=gcd(n1,n2);

        return (str1+str2).substr(0,len);
    }
};