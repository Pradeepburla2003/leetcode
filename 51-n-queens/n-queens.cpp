class Solution {
public:
    void fun(int i,int n,vector<vector<string>>&ans,vector<string>& s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        for(int j=0;j<n;j++){
            if(help(s,i,j,n)){
                s[i][j]='Q';
                fun(i+1,n,ans,s);
                s[i][j]='.';
            }
        }
    }
    bool help(vector<string>&s,int i,int j,int n){
        for(int row=0;row<i;row++){
            if(s[row][j]=='Q') return 0;
        }
        int row=i,col=j;
        while(row>-1 && col<n ){
            if(s[row][col]=='Q') return 0;
            row--;
            col++;
        }
        row=i,col=j;
        while(row>-1 && col>-1){
            if(s[row][col]=='Q') return 0;
            row--;
            col--;
        }
        return 1;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;

        vector<string> s(n,string(n,'.'));
        fun(0,n,ans,s);
        return ans;
    }
};