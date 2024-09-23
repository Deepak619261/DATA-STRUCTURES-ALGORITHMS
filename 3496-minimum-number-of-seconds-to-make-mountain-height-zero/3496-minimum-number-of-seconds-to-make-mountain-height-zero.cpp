class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        if(workerTimes.size()==1){
            long long multi=((long long)mountainHeight*(mountainHeight+1))/2;
            return (long long)(multi*workerTimes[0]);
        }

        //  we have to implement min heap 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;

        long long ans=0;

        for(int i=0;i<workerTimes.size();i++){
            q.push({workerTimes[i],{workerTimes[i],1}});
        }

        for(int i=0;i<mountainHeight;i++){
            auto it=q.top();
            long long Time_reached=it.first;
            long long original_time=it.second.first;
            long long steps_taken=it.second.second;
            q.pop();

            ans=Time_reached;

            q.push({Time_reached+(original_time*(steps_taken+1)),{original_time,steps_taken+1}});
        }
        return ans;
    }
};