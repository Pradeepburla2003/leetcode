class Solution {
public:
    int ans = 0;
    bool isSafe(vector<vector<string>>&puzzle,int i,int j,int n){
        int row = i-1,col = j;
        while(row >= 0){
            if(puzzle[row][col] == "1") return false;
            row--;
        }
        row = i - 1,col = j + 1;
        while(row>=0 && col<n){
            if(puzzle[row][col] == "1") return false;
            row--;
            col++;
        }
        row = i - 1,col = j - 1;
        while(row>=0 && col >=0){
            if(puzzle[row][col] == "1") return false;
            row--;
            col--;
        }
        return true;
    }
    void help(vector<vector<string>>&puzzle,int i,int n){
        if(i == n){
            ans++;
            return;
        }
        for(int k=0;k<n;k++){
            puzzle[i][k] = "1";
            if(isSafe(puzzle,i,k,n)) help(puzzle,i+1,n);
            puzzle[i][k] = "";
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>puzzle(n,vector<string>(n,""));
        help(puzzle,0,n);
        return ans;
    }
};