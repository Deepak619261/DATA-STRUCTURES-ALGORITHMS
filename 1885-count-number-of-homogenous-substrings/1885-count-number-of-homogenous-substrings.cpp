class Solution {
    const int MOD=1e9+7;
public:
    int countHomogenous(string s) {
       if(s.size()==1){
        return 1;
       }


       char prev=s[0];
       int n=s.size();


       int first=0;
       int second=0;
       long long ans=0;
       while(first<n && second<n){
        if(s[second]!=prev){
          long long cap=second-first;
          ans+=cap*(cap+1)/2;
          prev=s[second];
          first=second;
        }
        else{
            second++;
        }
       }
       if(first<n){
        long long cap=second-first;
        ans+=cap*(cap+1)/2;
       }

       return ans%MOD;
    }
};