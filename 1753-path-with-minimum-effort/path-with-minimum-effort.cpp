class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
                    ,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                //  cout<<"hi"<<endl;
                if(nrow<m and ncol>-1 and nrow>-1 and  ncol<n){
                    int absolute=abs(heights[nrow][ncol]-heights[row][col]);
                    int maxi=max(dis,absolute);
                    if(maxi<dist[nrow][ncol] or (row==0 and col==0)){
                        dist[nrow][ncol]=maxi;
                        pq.push({maxi,{nrow,ncol}});
                    }
                    
                }
            }
        }
        return dist[m-1][n-1];
    }
};