class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>&vis){
         int m=board.size();
         int n=board[0].size();
         vis[i][j]=1;
         int dr[]={-1,0,1,0};
         int dc[]={0,1,0,-1};
         for(int k=0;k<4;k++){
            int r=dr[k]+i;
            int c=dc[k]+j;
            if(r<0||r>=m||c<0||c>=n) continue;
            if(board[r][c]=='O'&&!vis[r][c]) dfs(board,r,c,vis);
         }
    }
    void solve(vector<vector<char>>& board) {
         int m=board.size();
         int n=board[0].size();
         vector<vector<int>>vis(m,vector<int>(n,0));
         for(int i=0;i<n;i++){
            if(board[0][i]=='O'&&!vis[0][i]) dfs(board,0,i,vis);
            if(board[m-1][i]=='O'&&!vis[m-1][i]) dfs(board,m-1,i,vis);
         }
         for(int i=0;i<m;i++){
            if(board[i][0]=='O'&&!vis[i][0]) dfs(board,i,0,vis);
            if(board[i][n-1]=='O'&&!vis[i][n-1]) dfs(board,i,n-1,vis);
         }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&!vis[i][j]) board[i][j]='X';
            }
         }
    }
};