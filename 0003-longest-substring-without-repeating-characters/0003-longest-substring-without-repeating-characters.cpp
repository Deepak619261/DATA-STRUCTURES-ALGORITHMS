class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int st=0;
        int e=0;
        unordered_map<int,int>mpp;
        int ans=0;

        while(st<n && e<n && st<=e){
            mpp[s[e]]++;
            while(mpp[s[e]]>1){
                mpp[s[st]]--;
                st++;
            }

            ans=max(ans,e-st+1);
            e++;
        }

        return ans;
    }
};