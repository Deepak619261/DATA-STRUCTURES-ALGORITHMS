class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
       for(auto it:words){
        int ind=it.find(pref);
        if(ind==0){
            count++;
        }
       }
       return count;   
    }
};