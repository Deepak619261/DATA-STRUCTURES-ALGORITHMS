class Solution {
    bool solve(vector<vector<char>>&board,int index,string word,vector<vector<int>>&vis,int row , int col,int m, int n){
        if(board[row][col]!=word[index]) return false;


        index++;
       
        if(index==word.size()){
            return true;
        }
        

        // traverse every direction and if current character is matching with the index increment the index


        

        vis[row][col]=1;
    

        


        bool up=false;
        if(row-1>=0 && !vis[row-1][col]){
            up=solve(board,index,word,vis,row-1,col,m,n);
        }
        bool down=false;
        if(row+1<m && !vis[row+1][col]){
            down=solve(board,index,word,vis,row+1,col,m,n);
        }
        bool left=false;
        if(col-1>=0 && !vis[row][col-1]){
            left=solve(board,index,word,vis,row,col-1,m,n);
        }
        bool right=false;
        if(col+1<n && !vis[row][col+1]){
            right=solve(board,index,word,vis,row,col+1,m,n);
        }

        vis[row][col]=0;


        return up|| down||right||left;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<vector<int>>vis(m,vector<int>(n,0));
                if(solve(board,0,word,vis,i,j,m,n)){
                    return true;
                }
            }
        }

        return false;
    }
};