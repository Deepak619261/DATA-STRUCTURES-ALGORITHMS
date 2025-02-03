class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // put every cell with the land cell in the queue and take the 
        // solving after seeing the hints , we will do BFS , this is similiar to the problem where we have to fill the matrix in maximum distance array , not able to reacall the exact problem name but that problem was visualisiing the drops in the lake and their effect -> rippling effect
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    q.push({0,{i,j}});
                    visited[i][j]=1;
                }
            }
        }


        // do the simplee BFS 
        int ans=INT_MIN;

        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans=max(ans,it.first);
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;
            cout<<row<<","<<col<<"-->"<<dist<<endl;

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol]){
                    visited[nrow][ncol]=1;
                    q.push({dist+1,{nrow,ncol}});
                }
            }

        }

        if(ans==INT_MIN || ans==0)return -1;
        return ans;

    }
};