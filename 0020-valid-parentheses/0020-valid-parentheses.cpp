class Solution {
public:
    bool isValid(string s) {
      // the conecpt is about matching the very recent opening bracket , and once that's matched moved to the previous one that can be solved with either two pointer or with a simple stack problem 
      // i will implement both of the approaches here 
      // stack one 
      if(s[0]=='}' || s[0]==']' || s[0]==')')return false;

      stack<char>st;


      int i=0;

      while(i<s.size()){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty())return false;

            int curr=s[i];
            int prev=st.top();
            if((s[i]==']' && prev=='[') || (s[i]=='}' && prev=='{') || (s[i]==')' && prev=='(')){
                st.pop();
            }
            else{
                return false;
            }

        }
        i++;
      }
      if(!st.empty())return false;
    return true;
    }
};