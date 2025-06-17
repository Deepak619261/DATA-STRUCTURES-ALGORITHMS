class Solution {
public:
    string generateTag(string caption) {
        string ans="#";

        bool first=false;
        int left=0;

        for(int i=0;i<caption.size() && left<caption.size();i++){
            if(caption[i]==' '){
               string str=caption.substr(left,i-left);
            //    cout<<str<<endl;
            transform(str.begin(), str.end(), str.begin(), ::tolower);
               str[0]=toupper(str[0]);
            //    cout<<str<<endl;
               ans+=str;
               left=i+1;
            //    cout<<ans<<endl;
            }
        }

        if(left<caption.size()){
            string str=caption.substr(left,caption.size()-left);
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            str[0]=toupper(str[0]);
            ans+=str;
        }
        ans[1]=tolower(ans[1]);
        // cout<<ans<<endl;

        if(ans.size()>100){
            return ans.substr(0,100);
        }

        return ans;
    }
};