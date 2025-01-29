class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int>st;

        // set stores the element in the sorted order
        
        for(auto it:points){
           st.insert(it[0]);
        }

        if(w==0)return st.size();

        vector<int>temp;

        for(auto it:st){
            temp.push_back(it);
            cout<<temp.back()<<" ";
        }


        int start=temp[0];
        int cnt=0;

        for(int i=0;i<temp.size();i++){
            if((temp[i]-start>w)){
                cnt++;
                start=temp[i];
            }
        }

        return cnt+1;

        
    }
};