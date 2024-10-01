class Solution {
public:
    bool help(vector<vector<char>>& board, string word,int pos,int i,int j,int m,int n,vector<vector<int>>&visited){
        if(pos == word.size()) return true;
        if(i < 0 or i >=m or j < 0 or j >=n or word[pos] != board[i][j] or visited[i][j]) return false;
        visited[i][j] = 1;
        if(help(board,word,pos+1,i+1,j,m,n,visited)) return true;
        if(help(board,word,pos+1,i,j+1,m,n,visited)) return true;
        if(help(board,word,pos+1,i-1,j,m,n,visited)) return true;
        if(help(board,word,pos+1,i,j-1,m,n,visited)) return true;
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(help(board,word,0,i,j,m,n,visited)) return true;
            }
        }
        return false;
    }
};