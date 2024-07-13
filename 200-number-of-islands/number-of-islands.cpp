class Solution {
public:
     void fun(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            safe(row+1,col,grid,vis,q);
            safe(row-1,col,grid,vis,q);
            safe(row,col+1,grid,vis,q);
            safe(row,col-1,grid,vis,q);
        }
    }
    void safe(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,queue<pair<int,int>>&q){
        int m=grid.size();
        int n=grid[0].size();
         if(i>=0 && j>=0 && i<m && j<n && vis[i][j]==0 and grid[i][j]=='1'){
            q.push({i,j});
            vis[i][j]=1;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=1 && grid[i][j]=='1'){
                    fun(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};