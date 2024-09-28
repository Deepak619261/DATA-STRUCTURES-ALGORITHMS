class Solution {
    string preprocess(string str){
        string ans="";
        ans+="^#";
        for(int i=0;i<str.size();i++){
            ans+=str[i];
            ans+='#';
        }

        ans+='$';
        return ans;
    }
public:
    string longestPalindrome(string s) {
        //  now move to the Manacher's algorithm 
        string str=preprocess(s);

        int n=str.size();
        vector<int>store(n,0);
        int C=0;
        int R=0;
        int maxLen=0;
        int Centerindex=0;


        for(int i=1;i<n-1;i++){
            int mirror=2*C-i;


            if(i<R){
                store[i]=min(R-i,store[mirror]);
            }

            while(str[i+1+store[i]]==str[i-1-store[i]]){
                store[i]++;
            }


            if(i+store[i]>R){
                C=i;
                R=i+store[i];
            }


            if(store[i]>maxLen){
                maxLen=store[i];
                Centerindex=i;
            }
        }

        int start=(Centerindex-maxLen)/2;
        return s.substr(start,maxLen);
    }
};