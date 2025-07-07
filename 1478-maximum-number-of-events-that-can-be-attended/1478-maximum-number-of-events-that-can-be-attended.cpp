class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        //  similiar to the merge interval problems 
        int maxi=0;
        
        for(int i=0;i<events.size();i++){
            maxi=max(maxi,events[i][1]);
        }
        sort(events.begin(),events.end());

        // they say that solution is to use greedy method , means we we will first see what is the max day , because we have to see how many events we can attend 
        // first pick the maximum day 


        int j=0;
        int count=0;
        priority_queue<int , vector<int>, greater<>>pq;

        for(int i=0;i<=maxi;i++){
            while(j<events.size() && events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
            }
            // pop out the days which are past for the current 
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                count++;
            }

        }

        return count;
    }
};