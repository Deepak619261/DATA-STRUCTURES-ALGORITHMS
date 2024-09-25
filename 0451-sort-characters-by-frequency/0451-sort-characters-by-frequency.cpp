class Solution {
public:
    string frequencySort(string s) {
        //  we can do the by creating max heap , we will store the character with the frequency count with the char , heap will be a pair freq, char 
       map<char,int>mpp;
       for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
       }

       priority_queue<pair<int,char>>q;
       for(auto it: mpp){
        char ch=it.first;
        int freq=it.second;
        q.push({freq,ch});
       }


       string ans="";

       while(!q.empty()){
        auto it=q.top();
        int len=it.first;
        char ch=it.second;
        string store(len,ch);
        ans+=store;
        q.pop();
       }


       return ans;
       

        
    }
};