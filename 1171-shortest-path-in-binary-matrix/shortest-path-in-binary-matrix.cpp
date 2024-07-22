class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        if(grid.size()==1) return 1;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        dis[0][0]=1;
        while(!q.empty()){
            int pathSum=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow<m and nrow>-1 and ncol<n and ncol>-1 and grid[nrow][ncol]==0){
                        if(nrow==m-1 and ncol==n-1) return pathSum+1;
                        if(dis[nrow][ncol]>pathSum+1){
                            dis[nrow][ncol]=pathSum+1;
                            q.push({pathSum+1,{nrow,ncol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};