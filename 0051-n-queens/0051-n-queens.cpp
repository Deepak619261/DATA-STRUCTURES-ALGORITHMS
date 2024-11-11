class Solution {
    void solve(int row, int col , vector<vector<string>>&ans, vector<string>board,int n,vector<int>&up, vector<int>&leftupdiag,vector<int>&rightupdiag){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(up[col]==0 && leftupdiag[row-col+n-1]==0 && rightupdiag[row+col]==0){
              leftupdiag[row-col+n-1]=1;
              up[col]=1;
              rightupdiag[row+col]=1;
              board[row][col]='Q';
              solve(row+1,col,ans,board,n,up,leftupdiag,rightupdiag);
              leftupdiag[row-col+n-1]=0;
              up[col]=0;
              rightupdiag[row+col]=0;
              board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        //  optimized approach where we just want to check if we can somehow optimize the check functino 
        vector<vector<string>>ans;
        vector<string>board(n);

        string str(n,'.');
        for(int i=0;i<n;i++){
            board[i]=str;
        }

        vector<int>up(n,0);
        vector<int>leftupdiag(2*n,0);
        vector<int>rightupdiag(2*n,0);
        solve(0,0,ans,board,n,up,leftupdiag,rightupdiag);
        return ans;
    }
};