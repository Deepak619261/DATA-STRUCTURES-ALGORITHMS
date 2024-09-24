class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        int arr2[26]={0};


        if(s.size()!=t.size()) return false;
        
        
        
        
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            arr2[t[i]-'a']++;
        }


        for(int i=0;i<26;i++){
            if(arr[i]!=arr2[i]) return false;
        }


        return true;

       
    }
};