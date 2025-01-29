class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());

        // int ans=0;
        
        int ans=1;
        int start=points[0][0];

        for(int i=0;i<points.size();i++){
            if(points[i][0]-start>w){
                ans++;
                start=points[i][0];
            }
        }

        return ans;


    }
};