class Solution {
public:
    int trap(vector<int>& height) {
        // the previous appraoach could be enhanced just via one suffix or one prefix array 
        // in that case we will traverse and keep the reocrd for one of the left side or right depending on from where we are taking the suffix 

        //  the optimal apporach --> for a water to calcualte we just want two things -> there exists something bigger on the left side and right side from the current eleement 
        int s=0;
        int e=height.size()-1;

        int leftmax=0;
        int rightmax=0;
        int answer=0;

        while(s<e){
            // if the first is lesser than the right 
            if(height[s]<=height[e]){
                if(leftmax>height[s]){
                    answer+=(leftmax-height[s]);
                }
                else{
                    leftmax=height[s];
                }
                s++;
            }
            else{
                if(rightmax>height[e]){
                    answer+=(rightmax-height[e]);
                }
                else{
                    rightmax=height[e];
                }
                e--;
            }
        }
        return answer;
    }
};