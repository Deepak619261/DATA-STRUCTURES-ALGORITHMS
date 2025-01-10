class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>count(27,0);

        

        for(auto it:words2){
            vector<int>temp(27,0);
            for(int i=0;i<it.size();i++){
                temp[it[i]-'a']++;
                if(temp[it[i]-'a'] > count[it[i]-'a']){
                    count[it[i]-'a']=temp[it[i]-'a'];
                }
            }
        }

        for(auto it:count){
            cout<<it<<",";
        }



        vector<string>ans;
        

        for(auto it:words1){
            vector<int>temp(27,0);
            for(int i=0;i<it.size();i++){
                temp[it[i]-'a']++;
            }
            bool flag=true;

            for(int i=0;i<27;i++){
                if(temp[i]<count[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(it);
            }
        }





        return ans;

    }
};