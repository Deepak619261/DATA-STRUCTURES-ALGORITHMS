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
    vector<vector<int>> generate(int numRows) {

        // vector<int>base(1,1);
        // vector<vector<int>>res;
        // res.push_back(base);

        // for(int i=1;i<numRows;i++){
        //     vector<int>lastappend=res.back();
        //     vector<int>temp(lastappend.size()+1,0);

        //     //  go from 1 to n-1 so say n=3 so go from 1 to <n-1 that is 1 to <2
        //     int n=temp.size();
        //     temp[0]=1;
        //     temp[n-1]=1;

        //     for(int i=1;i<n-1;i++){
        //         temp[i]=lastappend[i-1]+lastappend[i];
        //     }
        //     res.push_back(temp);
            
        // }

        // return res;
        vector<vector<int>>res;

        for(int i=0;i<numRows;i++){
            vector<int>temp(i+1,1);
            int col=i+1;
            for(int j=1;j<=i;j++){
                 long long fct=(1LL*(i+1-j)*temp[j-1])/j;
                 temp[j]=fct;
            }
            res.push_back(temp);

        }

        return res;
    }
};