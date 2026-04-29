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
            cout<<factorial(rowIndex,i)<<" ";
            ans[i]=factorial(rowIndex,i);
        }
        return ans;
    }
};