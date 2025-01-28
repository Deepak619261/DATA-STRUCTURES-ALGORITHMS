class Solution {
    int dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,int delrow[],int delcol[]){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0 || visited[row][col]==1){
            return 0;
        }

        visited[row][col]=1;
        cout<<row<<col<<endl;

        int ans=grid[row][col];

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            ans+=dfs(nrow,ncol,grid,visited,delrow,delcol);
        }
        
        return ans;
           
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        

        int ans=0;

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]!=0){
                    cout<<i<<j<<endl;
                    cout<<"entering the dfs"<<endl;
                    ans=max(ans,dfs(i,j,grid,visited,delrow,delcol));
                    cout<<"exit from dfs"<<endl;
                }
            }
        }

        return ans;
    }
};