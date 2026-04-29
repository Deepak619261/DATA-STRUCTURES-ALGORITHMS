class Solution {
    long long factorial(int row , int col){

        long long fact=1;
        for(int i=0;i<col;i++){
            fact=fact*(row-i);
            fact=fact/(i+1);
        }

        return fact;
    }
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int>ans(rowIndex+1,1);
        for(int i=1;i<rowIndex;i++){
            long long fct=(1LL*(rowIndex+1-i)*ans[i-1])/i;
            // fct=fct/i;
            // fct=fct*ans[i-1];
            ans[i]=fct;
        }

        //  time complextiy is O(rowIndex * rowIndex) as the complexity of the factorial is O(column)
        //  more optimized will be if we don't call the formula again and again 
        return ans;
    }
};