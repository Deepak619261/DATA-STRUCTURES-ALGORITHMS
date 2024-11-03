class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        //  we will be using a distance array to make sure we are taking the min distance
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;


        pq.push({0,{0,0}});


        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};


        while(!pq.empty()){
            auto it=pq.top();
            int time=it.first;
            int row=it.second.first;
            int col=it.second.second;

            pq.pop();

            if(row==n-1 && col==m-1){
                return time;
            }


            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow<n && ncol<m && nrow>=0 && ncol>=0){
                    int diff=max(time,moveTime[nrow][ncol])+1;

                    if(diff<distance[nrow][ncol]){
                        distance[nrow][ncol]=diff;
                        pq.push({diff,{nrow,ncol}});
                    }
                }
            }



        }


        return -1;

        
    }
};