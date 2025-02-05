class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // just count that only two words in a string should differ or zero 
        if(s1==s2)return true;

        int cnt=0;
        int firstind=-1;
        int secondind=-1;

        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
            cnt++;
            if(cnt>2)return false;
            if(cnt==1){
                secondind=i;
            }
            else{
                firstind=i;
            }
            }
        }

        // cout<<cnt<<endl;
        cout<<firstind<<secondind;

        return cnt==2 && s1[firstind]==s2[secondind] && s1[secondind]==s2[firstind];
    }
};