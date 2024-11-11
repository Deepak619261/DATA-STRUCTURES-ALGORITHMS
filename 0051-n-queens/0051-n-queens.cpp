class Solution {

    bool isvalid(vector<string>board, int row, int col,int n){
        // so we are traversing row wise so we will check in leftup diagonal , rightupdiagonal and upper 
        int i=row;
        int j=col;


       // check for the straight in the straight line 
        while(i>=0){
            if(board[i][j]=='Q') return false;
            i--;
        }

        i=row;
        j=col;

        // check for the upper left diagonal for that i-- , j--

        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }


        i=row;
        j=col;

        while(i>=0 && j<n){
            if(board[i][j]=='Q')return false;
            i--;
            j++;
        }


        return true;
    }
    void solve(vector<string>board,vector<vector<string>>&ans,int row, int col,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isvalid(board,row,col,n)){
                board[row][col]='Q';
                solve(board,ans,row+1,col,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);


        string str(n,'.');

        for(int i=0;i<n;i++){
            board[i]=str;
        }

        solve(board,ans,0,0,n);

        return ans;
    }
};