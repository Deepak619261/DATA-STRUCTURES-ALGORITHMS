class Solution {
public:
    int possibleStringCount(string word) {
        //  find out the continously repeated chars -1 + (one for original word)

        int count=0;
        int rec=1;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]){
                rec++;
            }
            else{
                count+=(rec-1);
                rec=1;
            }
        }

        cout<<word<<"--> "<<rec<<endl;

        if(rec>1){
            count+=(rec-1);
        }

        return count+1;
    }
};