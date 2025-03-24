class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int left=intervals[0][0];
        int rightlim=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>rightlim){
                vector<int>temp={left,rightlim};
                ans.push_back(temp);
                left=intervals[i][0];
                rightlim=intervals[i][1];
            }
            else{
                rightlim=max(rightlim,intervals[i][1]);
            }
        }
        
        vector<int>temp={left,rightlim};
        ans.push_back(temp);

        return ans;
    }
};