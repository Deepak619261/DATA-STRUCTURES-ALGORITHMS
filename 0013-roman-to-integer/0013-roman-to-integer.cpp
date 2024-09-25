class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mpp;

        //  do the mapping from roman to integer
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;


        int ans=0;
        int i=0;
        for(i=0;i<s.size()-1;i++){
            if(mpp[s[i]]<mpp[s[i+1]]){
                ans+=mpp[s[i+1]]-mpp[s[i]];
                i+=1;
                continue;
            }
            else{
                ans+=mpp[s[i]];
            }
        }
        
        if(i==s.size()-1){
            ans+=mpp[s.back()];
        }

        return ans;
    }
};