class Solution {
public:
    bool safe(vector<string>&temp,int row,int col,int n){
        int i=0,j=0;
        while(i<col){
            if(temp[row][i]=='Q') return 0;
            i++;
        }
        i=row-1,j=col-1;
        while(i>=0 && j>=0){
            if(temp[i][j]=='Q') return 0;
            i--;
            j--;
        }
        i=row+1,j=col-1;
        while(i<n && j>=0){
            if(temp[i][j]=='Q') return 0;
            i++;
            j--;
        }
        return 1;
    }
    void fun(int n,int col,vector<string>&temp,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(temp);
            return ;
        }
        for(int row=0;row<n;row++){
            if(safe(temp,row,col,n)){
                temp[row][col]='Q';
                fun(n,col+1,temp,ans);
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>temp(n,s);
        vector<vector<string>>ans;
        fun(n,0,temp,ans);
        return ans;
    }
};