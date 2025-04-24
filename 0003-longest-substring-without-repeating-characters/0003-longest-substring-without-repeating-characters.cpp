class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxi=0;

        int n=s.size();
        unordered_map<char,int>mpp;
        while(left<n && right<n){
             mpp[s[right]]++;
             while(mpp[s[right]]>1 && left<=right){
                  mpp[s[left]]--;
                  left++;
             }
             
             maxi=max(maxi,right-left+1);
             right++;
        }

        return maxi;
    }
};