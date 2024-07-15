class Solution {
public:
    void safe(int i,int j,int m,int n,queue<pair<int,int>>&q,vector<vector<int>>&grid,int vis[][11]){
        if(i>=0 and i<m and j>=0 and j<n and grid[i][j]==1 and vis[i][j]!=1){
            grid[i][j]=2;
            q.push({i,j});
            return ;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        // vector<vector<int>>visited(m,vector<in)
        int vis[11][11]={{0}};
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                vis[row][col]=1;
                q.pop();
                safe(row-1,col,m,n,q,grid,vis);
                safe(row+1,col,m,n,q,grid,vis);
                safe(row,col-1,m,n,q,grid,vis);
                safe(row,col+1,m,n,q,grid,vis);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        ans = (ans > 0) ? ans-1 : 0;
        return ans;
    }
};