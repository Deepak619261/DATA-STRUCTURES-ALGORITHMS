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
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y)return false;
        return target%gcd(x,y)==0;
    }
};