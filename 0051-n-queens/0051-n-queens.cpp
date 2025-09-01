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
    void solve(int row, int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isvalid(row,col,board,n)){
                board[row][col]='Q';
                solve(row,col+1,board,ans,n);
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
        solve(0,0,board,ans,n);
        return ans;
    }
};