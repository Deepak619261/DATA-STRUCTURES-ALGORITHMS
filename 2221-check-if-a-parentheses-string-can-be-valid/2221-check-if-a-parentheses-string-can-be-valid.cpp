class Solution {
public:
    bool canBeValid(string s, string locked) {
       if(s.size()%2!=0)return false;
       int maxi=0;
       int curr=0;

       for(int i=0;i<s.size();i++){
        if(locked[i]=='1'){
            if(s[i]=='('){
                curr++;
                maxi++;
            }
            else{
                curr--;
                maxi--;
            }
        }
        else{
             curr--;
             maxi++;
        }
        curr=max(curr,0);
        if(maxi<0){
            cout<<i<<endl;
            return false;
        }
       }

       if(curr!=0)return false;

       return true;


    }
};