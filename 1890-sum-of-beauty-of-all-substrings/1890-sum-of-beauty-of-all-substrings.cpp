class Solution {
public:
    int beautySum(string s) {
        

        // it can't be solved less than O(N^2 ) but we can do it efficiently in terms of space complexity 
        if(s.size()<=2){
            return 0;
        }
        int ans=0;


        for(int i=0;i<s.size();i++){
            map<char,int>mpp;
            for(int j=i;j<s.size();j++){
                int maxi=INT_MIN;
                int mini=INT_MAX;
                mpp[s[j]]++;

                for(auto it:mpp){
                    if(it.second>maxi) maxi=it.second;
                    if(it.second<mini) mini=it.second;
                }

                ans+=(maxi-mini);
            }
        }


        return ans;

        
    }
};