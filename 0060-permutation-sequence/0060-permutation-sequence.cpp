class Solution {
    string next_permutation(string str){
        int n=str.size();

        if(n==1)return str;
        int ind=-1;



        for(int i=n-2;i>=0;i--){
            int curr=str[i]-'0';
            int nexi=str[i+1]-'0';

            if(curr<nexi){
                ind=i;
                break;
            }
        }

        if(ind==-1)return str;

        int pivot=str[ind]-'0';

        for(int i=n-1;i>=0;i--){
            int curri=str[i]-'0';
            if(curri>pivot){
                swap(str[i],str[ind]);
                break;
            }
        }
        sort(str.begin()+ind+1,str.end());
        return str;
    }
public:
    string getPermutation(int n, int k) {
        //  going with the with the brute force 
        // will calculate the next_permutation till k times , 
        //  create the string 
        string str="";
        for(int i=1;i<=n;i++){
            str+=to_string(i);
        }

        for(int i=1;i<k;i++){
           str=next_permutation(str);
        //    cout<<"index -> "<<i<<" and str is "<<str<<endl;
        }

        return str;
    }
};