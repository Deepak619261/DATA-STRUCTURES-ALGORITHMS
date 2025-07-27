class Solution {
public:
    long long numOfSubsequences(string s) {
        // approach from gpt , we can do this without recursion actaully 
        //  first count existing LCT subsequence 
        // then with the help of prefix and suffix see for each characters , what is the maximum contribution we are getting 

        int n=s.size();
        long long currLCT=0;
        long long countL=0;
        long long countC=0;
        long long countT=0;

        for(auto it:s){
            if(it=='L')countL++;
            if(it=='C')countC+=countL;
            if(it=='T')countT+=countC;
        }

        vector<long long >prefixL(n+1,0);
        vector<long long>prefixLC(n+1,0);

        vector<long long >suffixT(n+1,0);
        vector<long long >suffixCT(n+1,0);

        for(int i=0;i<n;i++){
            prefixL[i+1]  = prefixL[i] + (s[i] == 'L');
            prefixLC[i+1] = prefixLC[i] + (s[i] == 'C' ? prefixL[i] : 0);
        }

        for(int i=n-1;i>=0;i--){
            suffixT[i]  = suffixT[i+1] + (s[i] == 'T');
            suffixCT[i] = suffixCT[i+1] + (s[i] == 'C' ? suffixT[i+1] : 0);
        }

        long long maxi=0;

        for(int i=0;i<=n;i++){
            long long maxL=suffixCT[i];
            long long maxC=prefixL[i]*suffixT[i];
            long long maxT=prefixLC[i];
            // cout<<i<<"--"<<maxL<<","<<maxC<<","<<maxT<<endl;
            maxi=max(max(maxi,maxL),max(maxC,maxT));
            // cout<<"maxi"<<maxi<<endl;    
        }

        // cout<<maxi<<endl;

        return maxi+countT;
    }
};