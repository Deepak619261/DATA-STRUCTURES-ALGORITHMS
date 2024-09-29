class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //  using map 
        map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        set<int>st;
        for(auto it:mpp){
           int occ=it.second;
           if(st.find(occ)!=st.end()) return false;
           st.insert(occ);
        }

        return true;
    }
};