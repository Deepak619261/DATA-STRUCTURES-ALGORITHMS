class Solution {
    bool DoesContainsZeros(int n){
        while(n){
            int x=n%10;
            if(x==0)return true;
            n=n/10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1;i<n;i++){
            int b=n-i;
            if(!DoesContainsZeros(b) && !DoesContainsZeros(i) ){
                return {i,b};
            }
        }
        return {};
    }
};