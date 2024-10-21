class Solution {
    static bool comp(vector<int>v1, vector<int>v2){
        if(v1[1]<v2[1]) return true;
        if(v1[1]>v2[1]) return false;

        if(v1[0]<v2[0]) return true;

        return false;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // return intervals;
        
        vector<vector<int>>ans;

        ans.push_back(intervals[0]);

        int lim=ans.back()[1];

        //  if the starting of the given interval is greater than the limit than for sure its a seprate interval 
        //  if its less than there may be two possiblity that the starting index of the current index is <= than the previous intervals starting index

        for(int i=1;i<intervals.size();i++){

            if(lim<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                // if(intervals[i][0]!=intervals[i][1]){
               ans.back()[0]=min(ans.back()[0],intervals[i][0]);
               ans.back()[1]=max(ans.back()[1],intervals[i][1]);
             
                // }
                // else{
                //     ans.push_back(intervals[i]);
                // }
            }
              lim=ans.back()[1];

        }

        return ans;

    }
};