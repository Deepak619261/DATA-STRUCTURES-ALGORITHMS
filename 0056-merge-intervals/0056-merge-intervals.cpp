class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        // return intervals;
        int first=intervals[0][0];
        int second=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int x=intervals[i][0];
            int y=intervals[i][1];
            if((x<=second && y<=second)){
                continue;
            }
            else if(x<=second){
                second=y;
            }
            else{
                ans.push_back({first,second});
                first=x;
                second=y;
            }
        }

        vector<int>last={first,second};

        if(ans.empty() || (!ans.empty() && ans.back()!=last))ans.push_back({first,second});

        return ans;
    }
};