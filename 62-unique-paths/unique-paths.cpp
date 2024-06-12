class Solution {
public:
    int ans=0;
    int paths(vector<vector<int>>&grid,int m,int n,int i,int j){
        if(m==i or n==j) return 0;
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(grid[i][j]!=0) return grid[i][j];
        grid[i][j]=paths(grid,m,n,i,j+1)+paths(grid,m,n,i+1,j);
        return grid[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        return paths(grid,m,n,0,0);
        
    }
};