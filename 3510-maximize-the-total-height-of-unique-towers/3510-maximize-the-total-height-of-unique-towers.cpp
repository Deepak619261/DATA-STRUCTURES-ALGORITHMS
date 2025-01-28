class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.rbegin(),maximumHeight.rend());
        for(auto it:maximumHeight){
            cout<<it<<" ";
        }
 
        long long answer=maximumHeight[0];

        for(int i=1;i<maximumHeight.size();i++){
            maximumHeight[i]=min(maximumHeight[i],maximumHeight[i-1]-1);
            if( maximumHeight[i]<=0)return -1;
            answer+= maximumHeight[i];
        }
        return answer;
    }
};