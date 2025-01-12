class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();

        // the last bracked can't be remain as open and locked 
        if((locked[n-1]=='1' && s[n-1]=='(') || s.size()%2!=0)return false;

        
        int fixedop=0;
        int varcnt=0;

       
        

       for(int i=0;i<s.size();i++){
          if(s[i]==')' && locked[i]=='1'){
             if(fixedop==0 && varcnt==0)return false;
             else if(varcnt!=0){
                varcnt--;
             }
             else if(fixedop!=0){
                fixedop--;
             }
          }
          else if(locked[i]=='1'){
                fixedop++;
          }
          else{
            varcnt++;
          }
       }
       

       fixedop=0;
       varcnt=0;

  for(int i=s.size()-1;i>=0;i--){
          if(s[i]=='(' && locked[i]=='1'){
             if(fixedop==0 && varcnt==0)return false;
             else if(varcnt!=0){
                varcnt--;
             }
             else if(fixedop!=0){
                fixedop--;
             }
          }
          else if(locked[i]=='1'){
                fixedop++;
          }
          else{
            varcnt++;
          }
       }
       
    





    return true;
        

    }
};