class Solution {
public:
    int myAtoi(string s) {

        long long answer=0;

        int i=0;
        // remove the whitespace 
        while(i<s.length() && (s[i]==' ')){
             i++;
        }

        // sign handled 
        bool ispos=true;
        if(i<s.length()){
            if(s[i]=='-'){
                ispos=false;
                i++;
            }
            else if(s[i]=='+')i++;
        }

        if(s[i]=='+' || s[i]=='-')return  0;


        while(i<s.length() && (s[i]=='0')){
             i++;
        }

        
        
        cout<<i<<endl;
        while(i<s.length()){
            if(s[i]>='0' && s[i]<='9'){
                answer=answer*10+(int)(s[i]-'0');
                cout<<i<<" ->"<<answer<<endl;
            }
            else{
                if(!ispos)return -answer;
                return answer;
            }
            if(!ispos && -answer<INT_MIN)return INT_MIN;
            if(ispos && answer>INT_MAX)return INT_MAX;
            i++;
        }
        // cout<<INT_MIN<<endl;
        if(!ispos)answer=-answer;

        if(answer<INT_MIN)return INT_MIN;
// cout<<"i am here2"<<endl;
        if(answer>=INT_MAX)return INT_MAX;

        // cout<<"i am here"<<endl;

        // if(!ispos)return -answer;
        return answer;
    }
};