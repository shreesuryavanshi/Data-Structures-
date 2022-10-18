class Solution {
public:
    void nQueen(int col,vector<string>&board,vector<vector<string>>&ans,
                int n,vector<int>&rowHash,vector<int>&lowerDiagHash,vector<int>&upperDiagHash){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(rowHash[row]==0 and lowerDiagHash[row+col]==0 and upperDiagHash[n-1+col-row]==0){
                board[row][col]='Q';
                rowHash[row]=1;
                lowerDiagHash[row+col]=1;
                upperDiagHash[n-1+col-row]=1;
                nQueen(col+1,board,ans,n,rowHash,lowerDiagHash,upperDiagHash);
                board[row][col]='.';
                rowHash[row]=0;
                lowerDiagHash[row+col]=0;
                upperDiagHash[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>rowHash(n,0),lowerDiagHash(2*n-1,0),upperDiagHash(2*n-1,0);
        nQueen(0,board,ans,n,rowHash,lowerDiagHash,upperDiagHash);
        return ans;
    }
};
