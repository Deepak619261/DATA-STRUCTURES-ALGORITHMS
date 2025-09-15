class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        //  pick the letter in set 
        unordered_set<char>st(brokenLetters.begin(),brokenLetters.end());
        //  extract word by word 
        string curr="";

        bool yes=false;

        int count=0;

        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(!yes){
                    count++;
                    cout<<"here  ---"<<i<<" ="<<text[i]<<yes<<endl;
                }
                yes=false;
            }
            else{
                if(st.count(text[i])>0){
                    yes=true;
                }
            }
        }
        // cout<<"here"<<count<<endl;
        if(!yes)count++;
        return count;
    }
};