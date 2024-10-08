class Solution {

public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<unsigned long int >prev(amount+1,0);

        //  tabulation 
        for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            prev[i]=1;
        }
        }
        
        
    for(int ind=1;ind<n;ind++){
        vector<unsigned long int>curr(amount+1,0);
        for(int j=0;j<=amount;j++){
            unsigned long int  taken=0;
            if(coins[ind]<=j){
                taken=curr[j-coins[ind]];
            }
            unsigned long int nottaken=prev[j];
            curr[j]=(taken+nottaken);
        }
        prev=curr;
    }


    return prev[amount];
    // return 0;


    }
};