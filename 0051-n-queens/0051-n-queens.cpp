class Solution {
    bool isvalid(int r, int c , vector<string>&board, int n){
        int row=r;
        int col=c;

        //  first check the upper left diagopnal side 
        while(row>=0 && col>=0){
            if(board[row--][col--]=='Q')return false;
        }

        row=r;
        col=c;

        while(row>=0 && col>=0){
            if(board[row][col--]=='Q')return false;
        }

        row=r;
        col=c;

        while(row<n && col>=0){
            if(board[row++][col--]=='Q')return false;
        }

        return true;

    }
    void solve(int row, int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>leftrow,vector<int>lowerdiag,vector<int>upperdiag){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiag[row+col]=1;
                upperdiag[n-1+col-row]=1;
                solve(row,col+1,board,ans,n,leftrow,lowerdiag,upperdiag);
                leftrow[row]=0;
                lowerdiag[row+col]=0;
                upperdiag[n-1+col-row]=0;
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string temp(n,'.');

        for(int i=0;i<n;i++){
            board[i]=temp;
        }
        vector<int>leftrow(n,0);
        vector<int>lowerdiag(2*n-1,0);
        vector<int>upperdiag(2*n-1,0);
        solve(0,0,board,ans,n,leftrow,lowerdiag,upperdiag);

        //  optimizing the solution by hashing 
        // the formula we have to remember 
        //  for left lower diagonal -> row+col 
        // for upper diagonal -> n-1+col-row
        return ans;
    }
};