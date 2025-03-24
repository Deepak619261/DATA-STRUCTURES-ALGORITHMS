class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans=0;

        

        sort(meetings.begin(),meetings.end());

        // cout<<ans;
        // prev=meetings[0][1];
        int rightlim=1;
        if(meetings[0][0]-rightlim>0){
            ans+=(meetings[0][0]-rightlim);
        }
        rightlim=max(rightlim,meetings[0][1]);

        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]-rightlim-1>0){
                cout<<meetings[i][0]<<"-"<<meetings[i][1]<<endl;
                ans+=meetings[i][0]-rightlim-1;
            }
            rightlim=max(rightlim,meetings[i][1]);
        }
        if(rightlim!=INT_MIN && days-rightlim>0){
          
            ans+=days-rightlim;
            // cout<<ans<<endl;
        }

        return ans;
    }
};