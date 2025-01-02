class Solution {
    bool Isvalid(string s){
        char first=s[0];
        char last=s.back();

        if((first=='a' || first=='e' || first=='i' || first=='o' || first=='u') && (last=='a' || last=='e' || last=='i' || last=='o' || last=='u')){
            return true;
        }

        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        //  ok i am writing whatever is coming to my mind :- so whenever i see 2D array and query the most obv thought comes to my mind is sweep line algorithm 
        //  okay getting the approach 
        //  what if we already store the in a vector which words are those which have starting with vowel and ending as well 
        //  then just using the sweep line algorithm , store in the vector 
        vector<int>temp;

        for(auto it : words){
            if(Isvalid(it)){
                temp.push_back(1);
            }
            else{
                temp.push_back(0);
            }
        }



       for(int i=1;i<temp.size();i++){
           temp[i]+=temp[i-1];
       }

        //  for eg:- [1,0,1,1,1]  -> queries are [0,2] , [1,4] , [1,1] 
        //  [1,1,2,3,4] -> 2,
        // [1,1,1]->[1,2,3] -> 

       vector<int>ans;

       for(auto it:queries){
          if(it[0]==0){
            ans.push_back(temp[it[1]]);
          }
          else{
            ans.push_back(temp[it[1]]-temp[it[0]-1]);
          }
       }


       return ans;
       
    }
};