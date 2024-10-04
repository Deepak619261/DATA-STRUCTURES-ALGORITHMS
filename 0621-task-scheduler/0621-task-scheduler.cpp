class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // implementation with priority queue 
        priority_queue<int>pq;

        unordered_map<char,int>mpp;

        for(char c : tasks){
            mpp[c]++;
        }
        
        for(auto it:mpp){
            pq.push(it.second);
        }

        queue<pair<int,int>>CDQ;
        //  freq, time 
        int currTime=0;

        while(!CDQ.empty() || !pq.empty()){
            currTime++;

            if(!CDQ.empty() && CDQ.front().second==currTime){
                pq.push(CDQ.front().first);
                CDQ.pop();
            }

            if(!pq.empty()){
                int maxfreq=pq.top();
                pq.pop();
                maxfreq--;

                if(maxfreq>0){
                    CDQ.push({maxfreq,currTime+n+1});
                }
            }
        }

        return currTime;
        
    }
};