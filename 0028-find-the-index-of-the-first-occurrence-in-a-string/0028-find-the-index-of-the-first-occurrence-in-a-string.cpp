class Solution {

    // z - algortihm 
    vector<int>getzvector(string str){
        int n=str.size();
        vector<int>Z(n,0);

        int L=0;
        int R=0;

        int i=0;

        while(i<n){
            //  there may be two possibilites one that we are iterating outside the Z-box
            if(i>R){
                   int R=i;
                   int L=i;

                   while(R<n && str[R-L]==str[R]){
                    R++;
                   }
                   Z[i]=R-L;
                   R--;
            }
            else{
            //  second is just opposite
            // here there exists two case first is that it is possible that 
            int k=i-L;




            //  first is that it is possible that the value we are putting fits in the Z box and second it doesn't fit in z box then we have recompare every thing 
            if(Z[k]<=R-i){
                Z[i]=Z[k];
            }
            else{
                
                L=i;
                 while(R<n && str[R-L]==str[R]){
                    R++;
                   }
                   Z[i]=R-L;
                   R--;
            }

            }
            i++;
        }


        return Z;
    }
public:
    int strStr(string haystack, string needle) {
        //  use black box technique in terms of thinking 

        string check=needle+"$"+haystack;

        vector<int>Z=getzvector(check);

        int size=needle.size();

        for(int i=0;i<Z.size();i++){
            if(Z[i]==size){
                return i-size-1;
            }
        }

        return -1;
    }
};