class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();

        vector<vector<int>>visited(m,vector<int>(n,-1));

        // developing intution 
        
        // doing this via watching its editorial , so for understanding this intution , first one should take a 1d array and take one water cell in that , and observe that , it heights are based on distance from the water cell , more the distance from the water cell , the greatest will be the height , 
        //now add one more water cell , now if the cell is between two water cell , then we have to fill the cell based on the continuation with the nearest possible water cell , 
        // the same logic applies with the 2-D grid , here we have to just do the same for the 2-d matrix 
        // for that we will use the BFS becasuse in BFS the cells are traversed level wise
        //         _
        //         ^
        //         |   
        //      _<-5->_
        //         |
        //         ~
        // so it covers the cell which are at the minimum distance from the water cell 
        // so we will put all the water cell and we will traverse the grid 

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j]=0;
                    visited[i][j]=1;
                }
            }
        }

        // define arrays for traversing in the four directions up , down , right , left
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        // down , right , up , left 


        int curr=1;
        // return isWater;
        while(!q.empty()){
            int size=q.size();

            while(size--){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            // visited[x][y]=1;

            for(int i=0;i<4;i++){
                
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && visited[nx][ny]==-1){
                        // fill the grid 
                        isWater[nx][ny]=curr;
                        visited[nx][ny]=1;
                        q.push({nx,ny});
                    }
                
            }
            }
           
           
            curr++;
           
        }
        return isWater;
    }
};