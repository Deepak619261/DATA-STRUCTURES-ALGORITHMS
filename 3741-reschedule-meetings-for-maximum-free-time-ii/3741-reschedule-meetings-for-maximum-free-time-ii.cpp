class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        // this question depends on how good you are at converting your approach into the code 
        // we can only once rearrange the meeting , we have to make the continouse gap we have only two options to do that , first one is that we can just move the block to the nearest block hence we will get the continouse array and the second option is that we can even move the block to another gap , in that gap we will have more continouse space two gap around that block and the space even that block was occupying 
        vector<int>gap;

        gap.push_back(startTime[0]-0);
        // every element in gap array is represeting the left part of gap for that block 

        for(int i=1;i<startTime.size();i++){
            gap.push_back(startTime[i]-endTime[i-1]);
        }

        gap.push_back(eventTime-endTime.back());


        //  for(auto i:largestRight)cout<<i<<"";
         cout<<endl;

        vector<int>nge(gap.size(),0);
        // nge[gap.size()-1]=gap.back();

        for(int i=gap.size()-2;i>=0;i--){
            nge[i]=max(nge[i+1],gap[i+1]);
        }

         for(auto it:nge)cout<<it<<"";
       // the game is here to correctly map the gap and nge array 
       // see the very first element of the gap array is the left gap of ith query so we want to check the size in next to just next gap of the current gap 
       // we want to map -> 1st element of the gap array with zeroth query 
       int largestleft=0;
       int ans=INT_MIN;
       for(int i=1;i<gap.size();i++){
        int currgap=endTime[i-1]-startTime[i-1];
        if(currgap<=max(largestleft,nge[i])){
            ans=max(ans,gap[i-1]+gap[i]+currgap);
            // gap[i-1]left part of the block 
            // gap[i] right part of the block 
            // currgap -> block itself
        }
        // we can't use else here because we have to take the max answer it is possible that some where it is giving max answer without shifting the block 
        ans=max(ans,gap[i-1]+gap[i]);
        
        largestleft=max(largestleft,gap[i-1]);
       }


        return ans;
    }
};