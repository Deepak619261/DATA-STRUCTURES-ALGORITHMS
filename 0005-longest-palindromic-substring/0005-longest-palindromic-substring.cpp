class Solution {
    string expand(string s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }

        return s.substr(left+1,right-left-1);
    }
public:
    string longestPalindrome(string s) {
        
        if(s.size()<=1) return s;
        
        string ans="";

        for(int i=0;i<s.size();i++){
            //  we have to consider both possiblities that string may came as even or odd length 
            string odd=expand(s,i,i);
            string even=expand(s,i,i+1);

            if(odd.size()>ans.size()){
                ans=odd;
            }

            if(even.size()>ans.size()){
                ans=even;
            }

        }


        return ans;
    }
};