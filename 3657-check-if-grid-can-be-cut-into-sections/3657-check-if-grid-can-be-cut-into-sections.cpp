class Solution {
    int merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int left=intervals[0][0];
        int rightlim=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=rightlim){
                vector<int>temp={left,rightlim};
                count++;
                // ans.push_back(temp);
                left=intervals[i][0];
                rightlim=intervals[i][1];
            }
            else{
                rightlim=max(rightlim,intervals[i][1]);
            }
        }
        
        // vector<int>temp={left,rightlim};
        // ans.push_back(temp);
        count++;

        return count;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // if you think carefully the whole problem sets up to the concept of merge intervals only 
        // store the  horizontally vertices 
        vector<vector<int>>xAxis;
        vector<vector<int>>yAxis;

        for(auto it:rectangles){
            xAxis.push_back({it[0],it[2]});
            yAxis.push_back({it[1],it[3]});
        }

        int vertical=merge(xAxis);
        int horizontal=merge(yAxis);


        

        return vertical>=3 || horizontal>=3;
        

       
        
    }
};