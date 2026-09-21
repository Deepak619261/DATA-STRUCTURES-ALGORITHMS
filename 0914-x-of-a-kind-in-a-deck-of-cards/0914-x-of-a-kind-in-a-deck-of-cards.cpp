class Solution {
    int gcd(int a,int b){
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
    bool hasGroupsSizeX(vector<int>& deck) {

        vector<int>mpp(1e4,0);

        for(auto it:deck){
            mpp[it]++;
        }
        
        int g=-1;

        for(int i=0;i<1e4;i++){
            if(mpp[i]>0){
                if(g==-1){
                    g=mpp[i];
                }
                else{
                    cout<<"before going "<<mpp[i]<<"annd  "<<g<<endl;
                    g=gcd(g,mpp[i]);
                    cout<<" after coming "<<g<<endl;
                }
                cout<<"at the occurence :- "<<mpp[i]<<" the g is :-"<<g<<endl;
            }
        }
        if(g>1)return true;

        return false;


        
    }
};