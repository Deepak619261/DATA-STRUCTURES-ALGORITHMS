class Solution {
public:
    char kthCharacter(int k) {
        string str="a";

        while(str.size()<k){
            //  take the current string add +1 to it 
            string toadd=str;
            for(int i=0;i<toadd.size();i++){
                if(toadd[i]=='z'){
                    toadd[i]='a';
                }
                else{
                    toadd[i]=toadd[i]+1;
                }
            }
            str+=toadd;
        }

        cout<<str<<endl;
        return str[k-1];
    }
};